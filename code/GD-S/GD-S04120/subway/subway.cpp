#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k1,k2,k3,ans;
int w[100005],ab[3][100005],t[3][100005];

void solve(int a,int b){
	ans=0;
	int vis;
	ans+=w[a];
	ans+=w[b];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(ab[1][i]==ab[2][j]){
				vis=i;
			}
		}
	}
	for(int i=a;i<=b;i++){
		if(i<=vis) ans+=t[1][i];
		if(i>=vis) ans+=t[2][i];
	}
	cout<<ans<<endl;
}

void solve3(int a,int b){
	ans=0;
	int vis1,vis2;
	ans+=w[a];
	ans+=w[b];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(ab[1][i]==ab[2][j]){
				vis1=i;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(ab[1][i]==ab[2][j]){
				vis2=i;
			}
		}
	}
	for(int i=a;i<=b;i++){
		if(i<=vis1) ans+=t[1][i];
		if(i>=vis1&&i<=vis2) ans+=t[2][i];
		if(i>=vis2) ans+=t[3][i];
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k1;
	for(int i=1;i<=k1;i++){
		cin>>ab[1][i]>>t[1][i];
	}
	cin>>k2;
	for(int i=1;i<=k2;i++){
		cin>>ab[2][i]>>t[2][i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	}
	if(n==3){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k1;
	for(int i=1;i<=k1;i++){
		cin>>ab[1][i]>>t[1][i];
	}
	cin>>k2;
	for(int i=1;i<=k2;i++){
		cin>>ab[2][i]>>t[2][i];
	}
	cin>>k3;
	for(int i=1;i<=k3;i++){
		cin>>ab[3][i]>>t[3][i];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		solve(x,y);
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
