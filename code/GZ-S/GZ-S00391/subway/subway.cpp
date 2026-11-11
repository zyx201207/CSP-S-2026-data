//GZ-S00391 岑巩县第一中学 吴先杰
#include <bits/stdc++.h>
using namespace std;

int dis[500010];
int r[100010];
int pas[500010];
int tc[510][500010];
int x[1000010];
int y[1000010];

int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin.tie(0);
	long long int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
	    cin>>dis[i];
	}
	int a,t,xianlu=1;
	for(int i=1;i<=n;i++){
		cin>>pas[i];
		for(int j=1;j<=pas[i]-1;j++){
			cin>>a>>t;
			tc[xianlu][a]==t;
		}
		xinalu++;
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i]
	}
	
	int ans=0;
	for(int final=1;final<=q;final++){
	
	
	
	
	
	
	
	cout<<ans;	
	}
	return 0;
}
