#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],nx[N],ls[M],lst[M],ans[M],cnt[M];
bool bj1[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        if(ls[a[i]])nx[i]=ls[a[i]];
        else ls[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int o=i;
        while(o<=n){
            if(bj1[o])break;
            bj1[o]=1;
            cnt[a[o]]++;
            if(cnt[a[o]]==1)lst[a[o]]=i;
            if(!nx[o])o++;
            else o=nx[o]+1;
        }
        int k=i-1;
        while(k&&k<o&&k<=n){
            bj1[k]=0;
            cnt[a[k]]--;
            if(cnt[a[k]]==0){
                ans[a[k]]+=i-lst[a[k]];
                lst[a[k]]=0;
            }
            if(!nx[k])k++;
            else k=nx[k]+1;
        }
    }
    for(int i=1;i<=m;i++)
        if(lst[i])
            ans[i]+=n-lst[i]+1;
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}
