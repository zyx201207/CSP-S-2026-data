#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
bool ok[N];
long long ans=-1;

void dfs(int level,long long sum){
	if(level==m){
		ans=max(ans,sum);
	}
	for(int i=1;i<=n;i++){
		if(ok[i]==false){
			ok[i]=true;
			if(level==0){
				dfs(level+1,a[i]);
			}
			else{
				dfs(level+1,sum&a[i]);
			}
			ok[i]=false;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
