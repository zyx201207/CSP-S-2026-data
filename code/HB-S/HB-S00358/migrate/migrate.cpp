#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
int a[101010];
map<int,int> mp;
void dfs(int now,int y,int step){
	if(now==y){
		mp[step]++;
		return ;
	}
	for(int i=now+1;i<=y;i++){
		if(a[i]-a[now]<=d){
			dfs(i,y,step+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j,0);
				if(mp[1]==2){
					cnt++;
					
				}
			}
		}
		mp.clear();
		cout<<cnt<<"\n";
	}
	
	return 0;
}
