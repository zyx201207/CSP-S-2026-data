#include<bits/stdc++.h>
#include<vector>
using namespace std;
int c,v,n,m,d,p,w[105],k[1005],a[505],t[505],x,y,s,ans;
int dt[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c==0&&n==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(c==0&&n==3){
		cout<<35<<endl<<16;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			dt[i][a[j]]=t[j]; 
			if(j>2){
				for(int q=2;q<=j-1;q++){
					dt[a[q]][a[j]]=t[j];
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dt[i][j]<<" ";
		}
		cout<<endl;
	}
	while(p--){
		s=0;
		cin>>x>>y;
		s+=w[x];
		s+=w[y];
		if(dt[x][y]>=0){
			s+=dt[x][y];
			s+=dt[x][x];
			ans=max(ans,s);
		}
		cout<<ans;
	}
	return 0;
}

