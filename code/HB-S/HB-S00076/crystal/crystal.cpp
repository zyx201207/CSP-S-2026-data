#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;

int n,m,a[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    } 
    sort(a+1,a+1+n);
    queue<int> q;int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&sum+q.size()*(a[i]-a[i-1])>m){
            sum-=a[i-1]-a[q.front()];
            q.pop();
        }
        sum+=q.size()*(a[i]-a[i-1]);
        q.push(i);
        ans=max(ans,(int)q.size());
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7

4
*/