#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m,ans=0;
void dfs(int sum,int pre,int used){
	if(used==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=pre+1;i<=n-(m-used)+1;i++){
		int k=sum&a[i];
		dfs(k,i,used+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int premax=0,sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			sum=a[i];
		}
		else{
			sum=sum&a[i];
		}
		premax=max(premax,a[i]);
	}
	if(m==1){
		cout<<premax;
		return 0;
	}
	else if(n==m){
		cout<<sum;
		return 0;
	}
	else if(m==2){
		int k;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				k=a[i]&a[j];
				ans=max(ans,k);
			}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n-m+1;i++)
			dfs(a[i],i,1);
		cout<<ans;
	}
	return 0;
}
