#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n,m;
struct edge{
	int a,cnt;
}e[N];
bool cmp(edge a,edge b)
{
	return a.cnt>b.cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>e[i].a;
		e[i].cnt=e[i].a-pow(2,floor(log2(e[i].a)));
	}
	sort (e+1,e+n+1,cmp);
	int ans=e[1].a;
	m--;
	for (int i=2;i<=n;i++)
	{
		if (!m)break;
		ans=ans&e[i].a;
		m--;
	}
	cout<<ans;
	return 0;
}
