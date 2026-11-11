#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[2000005];
bool check(int x,int y){
	int sum=0;
	for(int i=x;i+3<=y;i++)
		if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d)sum++;
	return sum==1;
}
int c1_ans1,c1_ans2;
void dfs1(int x,int s,int r){
	if(x==r){
		c1_ans1=min(c1_ans1,s);
		return ;
	}
	for(int i=x+1;i<=r&&a[i]-a[x]<=d;i++)dfs1(i,s+1,r);
}
void dfs2(int x,int s,int r){
	if(c1_ans2>2)return ;
	if(x==r){
		if(s==c1_ans1)c1_ans2++;
		return ;
	}
	if(s>c1_ans1)return ;
	for(int i=x+1;i<=r&&a[i]-a[x]<=d;i++)dfs2(i,s+1,r);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	if(c<=2){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					c1_ans1=1e18;
					dfs1(i,0,j);
					c1_ans2=0;
					dfs2(i,0,j);
					if(c1_ans2==2)ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else if(c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int ans=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(check(i,j))ans++,cout<<i<<" "<<j<<"\n";
			cout<<ans<<"\n";
		}
	}
	else {
		if(11<=c&&c<=12){
			
		}
	}
	return 0;
}

/*

*/



