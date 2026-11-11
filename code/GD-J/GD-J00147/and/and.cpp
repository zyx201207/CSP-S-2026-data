#include<bits/stdc++.h>
#define int long long
#define stp(x) fixed<<setprecision(x)
using namespace std;
const int N=2e5+10;
int a[N];
bool b[N];
int n,m;
inline int chk(int k){
	int res=0;
	for(int i=1;i<=n;i++)
		if(b[i]&&(a[i]&k))
			res++;
	return res;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=true;
	sort(a+1,a+n+1,[](const int&x,const int&y){return x>y;});
	for(int k=1<<30;k>0;k>>=1)if(chk(k)>=m)
		for(int i=1;i<=n;i++)
			if(!(a[i]&k))
				b[i]=false;
	int ans=LONG_LONG_MAX;
	for(int i=1;i<=n;i++)if(b[i])ans&=a[i];
	cout<<ans<<"\n";
	return 0;
}
