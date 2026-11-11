#include <iostream>
#include <cstdio>
using namespace std;
const int N=200005;
int n,a[N];
long long ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int L=1,R=n,AL=a[1],AR=a[n];
    char CL=c[1],CR=c[n];
    while(L<=R){
        if(CL==CR){
            if(AL<AR){
                L++;
                AR-=AL;
                AL=a[L];
                CL=c[L];
            }else if(AL>AR){
                R--;
                AL-=AR;
                AR=a[R];
                CR=c[R];
            }else{
                L++;
                R--;
                AL=a[L];
                CL=c[L];
                AR=a[R];
                CR=c[R];
            }
        }else{
            if(AL<AR){
                L++;
                AR-=AL;
                ans+=AL;
                AL=a[L];
                CL=c[L];
            }else if(AL>AR){
                R--;
                AL-=AR;
                ans+=AR;
                AR=a[R];
                CR=c[R];
            }else{
                L++;
                R--;
                ans+=AL;
                AL=a[L];
                CL=c[L];
                AR=a[R];
                CR=c[R];
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
