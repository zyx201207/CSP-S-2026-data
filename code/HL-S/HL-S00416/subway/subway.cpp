#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505][2][1005];
vetor<int> p[500005];
int ans=0;
void f(int a,int b)
{
	if(a==b) return ;
	int i=0,t,m=INT_MAX;
	while(p[i]!=0){
		if(m>p[i]){
			m=p[i];
			t=i;
		}
		i++;
	}
	ans+=m;
	a=t;
	f(a,b);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i][0][0];
		for(int j=1;j<=k[i][0][0];j++){
			cin>>k[i][0][j]>>k[i][1][j];
			p[j]+=i;
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		ans+=w[x];
		f(x,y);
		cout<<ans;
		ans=0;
	}
	return 0;
}