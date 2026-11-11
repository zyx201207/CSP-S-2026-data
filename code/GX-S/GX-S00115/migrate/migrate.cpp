#include<bits/stdc++.h>
using namespace std;
struct node{
    int time,days;
}dp[200010];
long a[200010];
int n;
int bfs(int x,int b[]){
    for(int i=1;i<=n;i++)dp[i]={0,0};
    queue<node> q;
    q.push({0,x});
    while(!q.empty()){
        node w=q.front();
        q.pop();
        for(int i=w.days;i<=b[w.days];i++){
            if(!dp[i].time){
                dp[i].time=w.time+1;dp[i].days=1;
                q.push({w.time+1,i});
            }
            else if(w.time+1==dp[i].time)dp[i].days++;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=(dp[i].days==2);
    }
    return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int d;cin>>n>>d;
        int b[200010];
        for(int i=1;i<=n;i++)cin>>a[i];
        int last=1;
        for(int i=1;i<=n;i++){
            int l=i,r=n;
            while(l<=r){
                int mid=(l+r)>>1;
                if(a[mid]-a[i]>d)r=mid-1;
                else l=mid+1;
            }
            b[i]=min(r,n);
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=bfs(i,b);
        }
        cout<<sum<<endl;
    }
    return 0;
}
