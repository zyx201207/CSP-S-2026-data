#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,v[500005];
int a1,a2,a3,a4,x,y;

//void dfs(int xx,int yy)
//{
//	for(int j=1;j<=n;j++){
//		if(a[xx][j]!=0){
//			ans+=a[xx][jj];
//			dfs(j,yy);
//		}
//	}
//}

//void A()
//{
//	for(int i=1;i<=m;i++){
//		cin>>v[i];
//	}
//	for(int i=1;i<=n;i++){
//		cin>>a1>>a2>>a3>>a4;
//		a[a1][a3]=a4;
//		a[a3][a1]=a2;
//	}
//	for(int i=1;i<=q;i++){
//		cin>>x>>y;
//		ans=0;
//		dfs(x,y);
//		cout<<ans<<'\n';
//	}
//}

//void N ()
//{
//	for()int i=1;i<=m;i++){
//		cin>>v[i];
//	}
//	for(int i=1;i<=q;i++){
//		cin>>
//	}
//}
//xei bu chu lai qwq
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a1;
		a1*=2;
		for(int j=1;j<=a1;j++){
			cin>>a2;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a3>>a4;
		cout<<v[a3]+v[a4]<<'\n';
	}
	return 0;//  =)
}
