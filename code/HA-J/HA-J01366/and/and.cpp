#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[200005],choos[25],ans;
void dfs(int lasid,int wilcho){
	if(wilcho==m+1){
		int a=choos[1];
		for(int i=2;i<=m;++i)
			a=a&choos[i];
		ans=max(a,ans);
		return;
	}
	
	for(int i=lasid+1;i<=n-(m-wilcho);++i){
		choos[wilcho]=a[i];
		dfs(i,wilcho+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n*m<=5000)
		dfs(0,1);
	else{
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;++i)
				ans=ans&a[i];
		}else{
			for(int i=1;i<=n;++i)
				ans=max(ans,a[i]);
		}
	}
	cout<<ans;
	
	return 0;
}
