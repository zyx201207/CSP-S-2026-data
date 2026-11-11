#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m,sum,last=1;
int ans=1;
int a[500005];
queue<int>que;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        if(sum<=m){
            sum=sum+(i-last)*(a[i]-a[i-1]);
            que.push(i);
        }
        else{
            int tmp=que.size();
            ans=max(ans,tmp-1);
            while(!que.empty()&&sum>m){
                sum=sum-abs((i-last)*a[que.front()]);
                ++last;
                que.pop();
            }
            if(que.empty()){
                sum=0;
            }
        }
    }
    int tmp=que.size();
    cout<<ans;
    return 0;
}
