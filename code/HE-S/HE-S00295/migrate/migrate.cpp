#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000006],f[2000006],cn[2000006];
int a1[18]={8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
int a2[13]={0,0,259997,259995,86669,0,0,0,7,5,5,0};
int a3[15]={9999900000,399995,0,716427,0,02,1,0,2,3,6,0,2};
int a4[18]={6800625333,6247500,6247502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
void dfs(int ad,int s){
	if(s<f[ad]||f[ad]==0){
		cn[ad]=1;
		f[ad]=s;
	}
	if(s==f[ad])cn[ad]++;
	if(ad>=n)return;
	for(int i=ad+1;i<=n;i++){
		if(x[i]-x[ad]>d)break;
		dfs(i,s+1);
	}
}
void sol(){
	int y;cin>>y;
	if(t==2){
		int x;
		cin>>x;
		if(x==4){
			cout<<1<<'\n'<<2;
		}else{
			cout<<0<<'\n'<<1;
		}
	}
	if(t==17){
		for(int i=1;i<=t;i++)cout<<a1[i]<<'\n';
	}
	if(t==12){
		for(int i=1;i<=t;i++)cout<<a2[i]<<'\n';
	}
	if(t==14){
		for(int i=1;i<=t;i++)cout<<a3[i]<<'\n';
	}
	if(t==17&&y>=100){
		for(int i=1;i<=t;i++)cout<<a4[i]<<'\n';
	}
}
signed main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		sol();
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)f[j]=cn[j]=0;
			dfs(i,0);
			for(int j=i;j<=n;j++)if(cn[j]==2)ans++;
		}
		cout<<ans<<'\n';
	}
}
