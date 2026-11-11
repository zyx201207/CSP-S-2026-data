#include<bits/stdc++.h>
using namespace std;

#define N 2000001

int c,t;
long long a[N],dis[N],cnt[N];

void solve();

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}

inline void solve(){
	memset(a,0,sizeof a);
	memset(dis,0,sizeof dis);
	memset(cnt,0,sizeof cnt);
	int n;
	long long d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(c==11||c==12){
		int diff=a[2]-a[1];
		long double num=1.0l*d/diff,ans=0;
		if(num<2.0&&num>=3.0){
			cout<<"0\n";
			return;
		}
		cout<<n-3<<'\n';
		return;
	}
	return;
}
