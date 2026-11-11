#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],l[N],ans[N],q[N];
int n,m;
void solve1(){
    for(int k=1;k<=n;k++){
        memset(l,0,sizeof(l));
        memset(q,0,sizeof(q));
        int t=1;
        for(int i=k;i<=n;i++){
            if(l[a[i]]){
                for(int j=l[a[i]]+1;j<t;j++){
                    l[q[j]]=0;
                    q[j]=0;
                }
                t=l[a[i]]+1;
            }
            else{
                l[a[i]]=t;
                q[t]=a[i];
                t++;
            }
        }
        for(int i=1;i<t;i++)ans[q[i]]++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve1();
    return 0;
}
