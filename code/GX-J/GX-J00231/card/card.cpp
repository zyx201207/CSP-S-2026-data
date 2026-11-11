#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans[N];
struct node{
    int w;
    bool f;
};
map<int,node>s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++)
            s[k].w=0,s[k].f=0;
        for(int j=i;j<=n;j++){
            if(s[a[j]].f){
                for(int k=s[a[j]].w;k<j;k++)
                    s[a[k]].f=0;
                s[a[j]].w=j;s[a[j]].f=1;
            }else s[a[j]].w=j,s[a[j]].f=1;
        }
        for(int i=1;i<=m;i++)
            if(s[i].f)ans[i]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
