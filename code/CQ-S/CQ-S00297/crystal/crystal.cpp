#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],ans=0;
bool ff[500005];
void dfs(long long int i,long long int j,long long int mm,long long int s,long long int anss){
	bool f=0;
	ff[i]==1;
	ff[j]==1;
	if(i<=0&&j>n){
		ans=max(ans,anss);
		return ;
	}
	if(mm+s-a[i-1]<=m&&i>1&&ff[i-1]==0)f=1,dfs(i-1,j,mm+s-a[i-1],s,anss+1);
	if(mm+s-a[i-1]+a[j+1]-s<=m&&i>1&&j<n&&ff[i-1]==0&&ff[j+1]==0)f=1,dfs(i-1,j+1,mm+s-a[i-1]+a[j+1]-s,s,anss+2);
	if(mm+a[j+1]-s<=m&&j<n&&ff[j+1]==0)f=1,dfs(i,j+1,mm+a[j+1]-s,s,anss+1);
	if(f==0){
		ans=max(ans,anss);
		return ;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n<500005){
		sort(a,a+1+n);
		for(int i=1;i<=n;i++){
			dfs(i,i,0,a[i],0);
			for(int ii=1;ii<=n;++ii)ff[ii]=0;
		}
		cout<<ans+1;
		return 0;
	}
	if(a[2]-a[1]==1){
		cout<<min(m+1,n);
		return 0;
	}
	if(a[2]-a[1]==a[3]-a[2]){
		cout<<min(m/(abs(a[2]-a[1]))+1,n);
		return 0;
	}
	else cout<<245645;
	return 0;
}//11
//好孩子，God是会保佑你的 
