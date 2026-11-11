#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010],stfa[2000010],refa[2000010],lefa[2000010],f[2000010],ans,vis[2000010];
void dfs(int x,int step){
	if (f[x]<step){
		return;
	}
	if (f[x]==step){
		if (vis[x]==0){
			vis[x]++;
		}else if (vis[x]==1){
			ans++;
			vis[x]++;
		}else if (vis[x]==2){
			ans--;
			vis[x]++;
		} 
	}
	if (f[x]>step){
		f[x]=min(f[x],step);
		vis[x]=1;
	}
	if (x==n){
		return;
	}
	if (stfa[x]!=0){
		dfs(stfa[x],step+1);
	}
	if (refa[x]!=0){
		dfs(refa[x],step+1);
	}
	if (lefa[x]!=0){
		dfs(lefa[x],step+1);
	}
	return;
} 
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i=1;i<=t;i++){
		cin >> n >> d;
		for (int j=1;j<=n;j++){
			cin >> x[j];
			lefa[j]=0;
			refa[j]=0;
			stfa[j]=0;
		}
		for (int j=1;j<=n;j++){
			int maxx=0,maxxx=0,maxxxx=0;
			for (int k=j+1;k<=n;k++){
				if (abs(x[k]-x[j])<=d){
					if (abs(x[k]-x[j])>maxx){
						maxx=abs(x[k]-x[j]);
						lefa[j]=refa[j];
						refa[j]=stfa[j];
						stfa[j]=k;
					}else if (abs(x[k]-x[j])>maxxx){
						maxxx=abs(x[k]-x[j]);
						lefa[j]=refa[j];
						refa[j]=k;
					}else if (abs(x[k]-x[j])>maxxxx){
						maxxxx=abs(x[k]-x[j]);
						lefa[j]=k;
					}
				}else{
					break;
				}
			}
		}
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				f[k]=2e9;
				vis[k]=0;
			} 
			vis[j]=3;
			f[j]=0;
			dfs(j,0);
		}
		cout << ans << endl;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
