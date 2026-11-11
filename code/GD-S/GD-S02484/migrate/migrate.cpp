#include<bits/stdc++.h>
using namespace std;
int a[1010];
int dis[1010][1010],ans[1010][1010];
void solve(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans[i][j]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1||n==2||a[n]-a[1]<=d){
		cout<<"0\n";
		return;
	}
	return;
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
