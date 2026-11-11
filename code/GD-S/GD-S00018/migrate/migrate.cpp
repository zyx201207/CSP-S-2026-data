#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000010];

int ans=0;
int cnt=0;
int ed=0;
void dfs(int x,int cn){
	if(x>=ed){
		cnt=cn;
		return;
	}
	int ne=lower_bound(a+1,a+n+1,a[x]+m)-a;
//	if(a[ne]-a[ne-1]>m)ne=min(ne-1,);
	if(a[ne]!=a[x]+m)ne--;
	dfs(ne,cn+1);
}
int mx;
void dfs2(int x,int cn){
	//cout<<x<<" "<<cn<<" ";
	if(cnt>2){
		return;
	}
	if(cn>mx)return;
	if(x==ed){
		//cout<<x<<"^"<<cn<<endl;
		cnt++;
		return;
	}
	
	int ne=lower_bound(a+1,a+n+1,a[x]+m)-a;
	
	if(a[ne]>a[x]+m)ne--;
	//cout<<x+1<<" "<<ne<<endl;
	for(int i=x+1;i<=min(ne,ed);i++){
		
		dfs2(i,cn+1);
	}
}
int dp[2000010];
void fun(){
	ans=0;
	cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]>m){
			n=i-1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0;
			ed=j;
			dfs(i,0);
			mx=cnt;
			cnt=0;
			dfs2(i,0);
			if(cnt==2){
				//cout<<i<<" "<<j<<" "<<mx<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	

	return;
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	int t;
	cin>>c>>t;
	while(t--){
		fun();
	}

	fclose(stdin);
	fclose(stdout);
}

