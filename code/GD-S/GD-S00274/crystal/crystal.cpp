#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define ms(a) memset(a,0,sizeof a)
#define int long long
#define pb push_back
#define Fopen(in) freopen(in".in","r",stdin),freopen(in".out","w",stdout);
using namespace std;
constexpr int N=5e5+5;

int n,m,a[N],p[N];
int sum(int l,int r){
	return a[r]*(r-l+1)-(p[r]-p[l-1]);
}
void solve(){
	cin>>n>>m;
	For(i,1,n)
		cin>>a[i];
	sort(a+1,a+1+n);
	For(i,1,n)
		p[i]=p[i-1]+a[i];
	int ans=1;
	for(int i=1,j=1;i<=n;){
		while(sum(j,i)>m && j<i)
			j++;
		ans=max(ans,i-j+1);
		i++;
	}
	cout<<ans<<'\n';
}
signed main(){
	Fopen("crystal")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
	return 0;  
}

// ？！Ametrine？！
// ？！Xterfusion！？
// X X XXX