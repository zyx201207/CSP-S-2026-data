#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[300005];
bool flag=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]<a[i-1])flag=1;
    }
    if(!flag){
        for(ll i=1;i<=n;i++)
            b[a[i]]=i;
        for(ll i=1;i<=m;i++)cout<<b[i]<<" ";
    }else{
        for(ll i=1;i<=n;i++)b[a[i]]=i;
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(i==j){
                    for(ll k=i;k<=j;k++)b[a[i]]--;
                }
            }
        }
        for(ll i=1;i<=m;i++)cout<<b[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
