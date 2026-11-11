#include<bits/stdc++.h> 
#define int long long
#define mem(a) memset(a,0,sizeof(a))
#define size(s) ((int)(s.size()))

using namespace std;

bool ppp;

const int N=5e5+5;

long long n,m,a[N],s[N],ans;

bool qqq;

bool pd(int l,int r){
	return (r-l+1)*a[r]-(s[r]-s[l-1])<=m;
}

signed main(){
//	cerr<<((&ppp)-(&qqq))/1048576.0<<"\n";
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	int l=1;
	for(int r=1;r<=n;r++){
		while(!pd(l,r)) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
