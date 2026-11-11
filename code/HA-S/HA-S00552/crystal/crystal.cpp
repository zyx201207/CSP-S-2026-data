#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m,ans,sum,a[500010],b[50];
void dfs(int pos,int sum){
	if(sum==m&&pos==n){
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			b[a[i]+20]++;
			ans=max(ans,b[a[i]+20]);
		}
		return;
	}
	if(pos==n){
		return;
	}
	for(int i=0;i<=m-sum;i++){
		a[pos+1]+=i;
		dfs(pos+1,sum+i);
		a[pos+1]-=i;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		sum+=a[n]-a[i];
	}
	if(sum<=m){
		cout<<n;
		return 0;
	}
	if(n<=5&&m<=10){
		dfs(0,0);
	}
	else{
		for(int i=1;i<=n;i++){
			long long ans1=1,t=m;
			for(int j=i-1;j>=1;j--){
				if(t>=a[i]-a[j]){
					t-=a[i]-a[j];
					ans1++;
				}
				else{
					break;
				}
			}
			ans=max(ans,ans1);
		}
	}
	cout<<ans;
	return 0;
}//45
