#include <bits/stdc++.h>
using namespace std;
int a[200005];
int ans=0;
int n,m;
void dfs(int j,int tmp,int sum){
	if(tmp==0){
		ans=max(ans,sum);
		return;
	}
	for(int i=j+1;i<=n;i++){
		int temp=sum&a[i];
		dfs(i,tmp-1,temp);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2&&n<40000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int temp=a[i]&a[j];
				ans=max(ans,temp);
			}
			
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)	ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(i,m-1,a[i]);
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans;
	return 0;
}
