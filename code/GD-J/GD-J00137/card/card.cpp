#include<bits/stdc++.h>
using namespace std;
int a[500010];
int res[300010];
bool mark[300010];
int pos[300010],cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(mark[a[i]]){
            continue;
        }else if(a[i]==a[n]){
            res[a[i]]+=cnt[a[i]];
            mark[a[i]]=1;
            continue;
        }
        int l=pos[a[i]];
        int sum=0;
        for(int j=l;j<=n;j++){
            if(!mark[a[j]]){
                sum+=cnt[a[j]];
            }
            res[a[j]]+=sum;
            mark[a[j]]=1;
            j=pos[a[j]];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
// [385,400]pts
