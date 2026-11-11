#include<iostream>
using namespace std;
long long a,b[200005],cnt,k;
bool c[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>k;
    for(int n=1;n<=a;n++){
        cin>>b[n];
    }
    for(long long n=30;n>=0;n--){
        long long x=1LL<<n,ans=0;
        for(int m=1;m<=a;m++){
            if((b[m]&x)&&!c[m]){
                ans++;
            }
        }
        if(ans>=k){
            cnt+=x;
            for(int m=1;m<=a;m++){
                if(!(b[m]&x)){
                    c[m]=1;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
