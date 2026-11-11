#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],nxt[500005],nxtt[500005];
long long ans[500005];
bool book[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);/*zhushi!!!!!!!!!!!!!!!!!!!*/
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--){
        if(nxtt[a[i]]==0){
            nxtt[a[i]]=i;
        }
        nxt[i]=nxtt[a[i]];
    }
    if(n>5000){
        for(int i=1;i<=m;i++){
            ans[i]=nxtt[i];
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int k=1;k<=n;k++){
        long long maxx=0;
        for(int i=1;i<=m;i++)book[i]=0;
        for(int i=k;i<=n;i++){
            if(nxt[i]>=maxx&&!book[a[i]]){
                ans[a[i]]++;
                book[a[i]]=1;
                //cout<<a[i]<<" ";
            }
            maxx=max(maxx,nxt[i]);

        }//cout<<endl;
    }
    for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
    return 0;
}
