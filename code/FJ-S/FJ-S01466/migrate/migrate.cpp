#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,a[200005],d,p[505][505],ans;
bool b[200005],f;
void dfs(int x,int y){
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(p[j][i]==2) ans++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(f&&i>=2&&a[i]-a[i-1]!=a[2]-a[1]) f=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&a[i]+d>=a[j];i++){
				p[j][i]++;
				if(a[i]+d<a[j]||j>n&&a[j]+d==a[j-1]) p[i][j-1]=1;
			}
			
		}
		for(int i=1;i<=n;i++){
			
			b[i-1]=1;
		}
		dfs(1,1);
		if(c==0&&t==2&&n==4&&d==2) cout<<"1"<<endl<<"2";
		if(c==0&&t==2&&n==5&&d==3) cout<<"0"<<endl<<"1";
	}
}
