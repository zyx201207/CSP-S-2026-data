#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N = 5e5+10;
ll n,m;
ll a[N],maxx,llll;
int dfs(int n_1,int m_1,int now){
    m_1=m_1-a[n_1]+a[now-1];
    if(m_1>0){dfs(n_1,m_1,now-1);}
    if(m_1<=0||now==0){llll=n_1-now+1;return 0;}
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n+1);
    for(int i=n;i>1;i--){
        dfs(i,m,i);
        maxx=max(maxx,llll);
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
