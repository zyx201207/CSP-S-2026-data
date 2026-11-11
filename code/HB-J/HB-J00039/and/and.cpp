#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N][32],n,m,ans[32];
queue<int> q;
queue<int> p;
long long calc(long long a,long long b){
    long long ans=1;
    for (int i=1;i<=b;i++)ans*=a;
    return a;
}
signed main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1,x;i<=n;i++){
        cin>>x;
        q.push(i);p.push(i);
        for (int j=0;j<=30;j++)
            if ((x>>j)&1)a[i][j]=1;
    }
    for (int j=30;j>=0;j--){
        int tmp=0;
        while (!q.empty()){
            int i=q.front();q.pop();p.push(i);
            if (a[i][j])tmp++,q.push(i);
        }
        if (tmp<m){
            while (!p.empty()){
                q.push(p.front());p.pop();
            }
            continue;
        }
        while (!p.empty())p.pop();
        ans[j]=1;
    }
    long long sum=0;
    //for (int i=30;i>=0;i--)sum+=(long long)ans[i]*calc(2LL,i);
    cout<<sum;
    return 0;
}
