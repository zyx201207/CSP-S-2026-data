#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=N;
int n,m;
int a[N];
int last[M];
int cnt[M];
int ans[M];
int s[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        last[a[i]]=i;
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        s[last[i]]+=cnt[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]){
            ans[a[i]]=s[i];
            s[last[a[i+1]]]+=s[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
