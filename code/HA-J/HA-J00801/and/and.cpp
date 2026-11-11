#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200000]={};
long long ans=0;

void dfs(int x,int s,long long an){
	if (x==0){
		if (an>ans) ans=an;
		return ;
	}
	for (int i=s;i<=n;i++){
		if (x==m) an=a[i];
		dfs(x-1,i+1,an&a[i]);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if (n<=2000){
		dfs(m,1,1);
	}else if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else{
		ans=a[n];
		for (int i=1;i<m;i++){
			ans=ans&a[n-i];
		}
	}
	cout<<ans;
	return 0;
}
