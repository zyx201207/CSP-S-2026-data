#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long ans;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int p=1,q=n;
    while(p<q){
        if(c[p]==c[q]){
            if(a[p]>a[q]){
                a[p]-=a[q];
                q--;
            }else if(a[p]<a[q]){
                a[q]-=a[p];
                p++;
            }else{
                p++;
                q--;
            }
        }else{
            if(a[p]>a[q]){
                a[p]-=a[q];
                ans+=a[q];
                q--;
            }else if(a[p]<a[q]){
                a[q]-=a[p];
                ans+=a[p];
                p++;
            }else{
                ans+=a[p];
                p++;
                q--;
            }
        }
    }
    cout<<ans;
    return 0;
}
