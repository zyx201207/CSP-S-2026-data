#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],b[100005];
ll ans,cnt,maxx=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cnt=m;
        for(int j=1;j<=n;j++){
            ans=0;
            while(a[i]==a[j]&&i!=j){
                if(cnt>0){
                    cnt--;
                    a[i]++;
                }
                else{
                    break;
                }
            }
            if(a[i]==a[j]&&i!=j){
                ans+=2;
            }
            if(ans<maxx){
                a[i]=b[i];
            }
        }
        maxx=max(maxx,ans);
    }
    cout<<maxx;
    return 0;
}
