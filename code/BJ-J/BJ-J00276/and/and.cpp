#include<bits/stdc++.h>
using namespace std;
priority_queue<long long>q,p;
long long n,m,a[200005],ans=0,cnt=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=30;j++){
            if(a[i]==pow(2,j)-1)p.push(a[i]);
        }
        q.push(a[i]);
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<q.top();
        return 0;
    }
    if(m==2&&n<=2000){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                long long y=a[i]&a[j];
                maxn=max(maxn,y);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==2&&!p.empty()){
        long long maxn=0;
        for(int i=1;i<=n;i++){
            long long y=p.top()&a[i];
            maxn=max(maxn,y);
        }
        cout<<maxn;
        return 0;
    }
    ans=q.top();
    q.pop();
    bool flag=0;
    for(int i=2;i<=m;i++){
        if(cnt==(n-m))flag=1;
        long long x=q.top();
        while(ans&x==0&&flag==0){
            q.pop();
            cnt++;
            x=q.top();
        }
        ans=ans&x;
        q.pop();
    }
    cout<<ans;
    return 0;
}