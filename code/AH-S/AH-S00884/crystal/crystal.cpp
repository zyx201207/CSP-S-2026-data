#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+5,M=2e6+5,INF=-0x7f7f7f7f;
LL a[N],gs[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	LL n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		LL x;
		cin>>x;
		x+=100001;
		if(gs[x]==0){
			a[++cnt]=x;
		}
		gs[x]++;
	}
	sort(a+1,a+cnt+1);
	LL ans=INF;
	LL mm=m;
	for(LL i=1;i<=cnt;i++){
		LL w=i,sum=0;
		m=mm;
		while(m>0&&w>0){
			m-=(a[i]-a[w])*gs[a[w]];
			sum+=gs[a[w]];
			w--;
		}
		if(m<0){
			w++;
			m+=(a[i]-a[w])*gs[a[w]];
			sum-=gs[a[w]];
			sum+=(m/(a[i]-a[w]));
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

