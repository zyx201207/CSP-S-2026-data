#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m,pre[N];
bool cmp(int b,int c){return b>c;}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(a[1]-a[i]);
    //pre[j]-pre[i]-(j-i)*(a[1]-a[i])
    int num=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n,ans=-1;
        while(l<=r){
            int j=(l+r)/2;
            if(pre[j]-pre[i]-(j-i)*(a[1]-a[i])<=m){
                ans=j;
                l=j+1;
            }else{
                r=j-1;
            }
        }
        num=max(num,ans-i+1);
    }
    cout<<num<<endl;
    return 0;
}