#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005],t[300005];
bool flag;
signed main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]<a[i-1]) flag=1;
}
if(flag==0){
    int l=1,r=1;
    a[n+1]=a[n]-1;
    while(r<=n+1){
        if(a[l]!=a[r]) ans[a[l]]+=r-1,l=r;
        r++;
    }
}else{
    for(int i=1;i<=n;i++){
            deque<int> que;
            memset(t,0,sizeof(t));
        for(int j=i;j<=n;j++){
            t[a[j]]++;
            while(t[a[j]]>1&&!que.empty()){
                t[que.back()]--;
                que.pop_back();
            }
            que.push_back(a[j]);
        }
        while(!que.empty()){
            ans[que.back()]++;
            que.pop_back();
        }
    }
}
for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
return 0;
}
