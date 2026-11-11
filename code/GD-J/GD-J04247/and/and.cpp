#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
vector<int> path;
bool used[200010];

void dfs(int now,int lst){
	if(now==m+1){
		int sum=path[0];
		for(int i=1;i<path.size();i++){
			sum&=path[i];
//			cout<<path[i]<<" ";
		}
//		cout<<"\n"<<sum<<"\n";
		ans=max(ans,sum);
		return ;
	} 
	for(int i=lst;i<=n;i++){
		if(!used[a[i]]){
			path.push_back(a[i]);
			used[a[i]]=1;
			dfs(now+1,i+1);
			used[a[i]]=0;
			path.pop_back();
		}
	}
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
//	cout<<n<<"\n"; 
	for(int i=1;i<=n;i++) cin>>a[i];
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(m==n-1){
		
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==1){
		int Max=0;
		for(int i=1;i<=n;i++) Max=max(Max,a[i]);
		cout<<Max;
	}
	else if(n<=20){
		dfs(1,1);
		cout<<ans;
	}
	return 0;
} 
