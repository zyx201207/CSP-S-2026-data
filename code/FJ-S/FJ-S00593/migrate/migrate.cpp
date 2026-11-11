#include<bits/stdc++.h>
using namespace std;
int a[2000001],ans=0,n,d,minn,sum;
void dfs(int x,int y,int t){
	if(x>y||x>n||x<1)return;
	if(x==y&&t==minn){
		sum++;
		return;
	}
	for(int i=d;i>=1;i--){
		dfs(x+i,y,t+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n-d;i++){
			for(int j=i+d;j<=n;j++){
				sum=0;
				if((a[j]-a[i])%d)minn=((a[j]-a[i])-(a[j]-a[i])%d)/d+1;
				else minn=(a[j]-a[i])/d;
				dfs(i,j,0);
				if(sum==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
