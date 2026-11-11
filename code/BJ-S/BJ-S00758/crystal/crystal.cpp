#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N];
queue<long long>c;
priority_queue<long long,vector<long long>,greater<long long>> q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(a[i]);
    }
    long long x=q.top(),pay=0,cnt=1,ans=1;
    q.pop();
    c.push(x);
    for(long long i=1;i<n;i++){
        long long y=q.top();
        q.pop();
        while((y-x)*cnt+pay>m){
            long long fw=c.front();
            c.pop();
            cnt--;
            pay-=x;
            pay+=fw;
        }
        pay=(y-x)*cnt+pay;
        cnt++;
        c.push(y);
        ans=max(cnt,ans);
        x=y;
    }
    cout<<ans;
    return 0;
}
