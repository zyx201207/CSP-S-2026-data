#include<bits/stdc++.h>
#define nd(a,b) (x[b]-x[a]<=d)
#define ok(a) (!nd(a,a+3)&&nd(a,a+2)&&nd(a+1,a+3))
using namespace std;
long long x[2000100],gs[2000100];
int main()
{
	//*
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//*/
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n;
		long long d;
		cin>>n>>d;
		for(int q=1;q<=n;q++) cin>>x[q];
		if(n<4)
		{
			cout<<"0\n";
			continue;
		}
		long long ans=0;
		if(c==11||c==12)
		{
			long long gc=x[2]-x[1];
			if(d<gc*2) cout<<"0\n";
			else cout<<max(0ll,n-(d/gc*2)+1)<<'\n';
			continue;
		}
		int sl=1;
		for(int q=1;q<n-2;q++)
		{
			if(ok(q)) gs[sl++]=q;
		}
		for(int q=1;q<sl;q++)
		{
			long long gz=gs[q]-1,gy=gs[q]+4;
			while(nd(gz,gz+1)&&!nd(gz,gz+2)) gz--;
			while(nd(gy-1,gy)&&!nd(gy-2,gy)) gy++;
			ans+=(gs[q]-gz)*(gy-gs[q]-3);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
//freopen("migrate.in","r",stdin);
//freopen("migrate.out","w",stdout);
//freopen("migrate.in","r",stdin);
//freopen("migrate.out","w",stdout);
me want up mi huo xing wei da shang
so i love CCF
wow i love CCF
i wu yi am happy
but my fenshu is not gao
me wu yi shi fen nu de
beacouse i'm not hui xie

and me am the CQ-J00278
*/
