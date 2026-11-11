#include<bits/stdc++.h>
using namespace std;
long long n,a[2000005],ans[2000005],d,t;
int c;
vector<int> v[2000005];
void dfs(int now,int ans){
	if(now)
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[j]-a[i]<=d)&&(i!=j))v[i].push_back(j);
				else break;
			}
		}
		dfs(1,0);
		
	}
	return 0;
}
