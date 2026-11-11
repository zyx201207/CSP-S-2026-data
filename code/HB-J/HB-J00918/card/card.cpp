#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll p=n;
    for(;p>0;p--){
    bool book[1000005]={0};
        for(int i=n-p+1;i<=n;i++){
            int x=a[i];
            if(book[x]!=0){
                for(int j=0;j<=m;j++){
                    if(book[j]>=book[x])
                        book[j]=0;
                }
            }
            book[x]=i;
        }
        for(int j=0;j<=m;j++){
            if(book[j])
                ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
