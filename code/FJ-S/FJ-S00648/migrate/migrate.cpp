#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],b[3005][3005],k,km,ans;
void dfs(long long s,long long x,long long y){
	if(x==y){
		if(s<km){
			km=s;
			k=1;
		}
		else if(s==km) k++;
		return ;
	}
	for(int i=x+1;i<=y;i++){
		if(b[x][i]==1) dfs(s+1,i,y);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			b[i][i]=1;
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					b[i][j]=1;
					b[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				k=0;
				km=1e17;
				dfs(0,i,j);
				if(k==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
