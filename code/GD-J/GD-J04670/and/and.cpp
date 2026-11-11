#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e5+5,WS=45;
int n,m;
ll a[MAXN],ans[WS],s;
vector<bool> f[MAXN];
bool bj[MAXN];
void pre(int i,int x)
{
	while(x>0){
		f[i].push_back(x&1);
//		cout<<i<<' '<<(x&1)<<'\n';
		x>>=1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre(i,a[i]);
	}
	for(int i=29;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(i<f[j].size()&&!bj[j]&&f[j][i]==1) cnt++;
		if(cnt>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++)
				if(i>=f[j].size()||(!bj[j]&&(!f[j][i])))
					bj[j]=1;
		}
	}
	for(int i=29;i>=0;i--)
		s=s*2+ans[i];
	printf("%lld",s);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

2 1
2 4
*/
