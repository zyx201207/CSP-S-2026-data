#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500010];
int f[5010][5010];
int k;
int a[500010],t[500010];
int top;
int x,y;
int ans;

void floyd(){
	for(int k=1;k<=top;k++){
		for(int i=1;i<=top;i++){
			for(int j=i+1;j<=top;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=min(f[j][i],f[j][k]+f[k][i]);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++) f[i][j]=0x3f3f3f3f;
		f[i][i]=0;
	}
	top=m;
	while(n--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
			f[a[i]][++top]=t[i];
			f[top][a[i]]=t[i];
			if(i!=1){
				f[top-1][top]=0;
				f[top][top-1]=0;
			}
		}
		f[top][top-k+1]=0;
		f[top-k+1][top]=0;
	}
	floyd();
	while(q--){
		cin>>x>>y;
		ans=f[x][y]+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
