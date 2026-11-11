#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],t[M],ans[M],cnt=0;
struct node{
    int nu=0,w=1;
}pos[N];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
        if(t[a[i]]>=2){
            pos[++cnt].w=i;
            pos[cnt].nu=a[i];
        }
    }
    if(pos[cnt].w==0){
        for(int i=1;i<=n;i++){
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        for(int i=1;i<=n;i++){
            pos[i-1].nu=pos[i-1].w=0;
            t[a[i-1]]--;
            if(t[a[i-1]]==1){
                for(int j=)
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<' ';
        }
    }
    return 0;
}
