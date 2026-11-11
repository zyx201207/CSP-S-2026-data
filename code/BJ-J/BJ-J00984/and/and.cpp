#include<iostream>
using namespace std;
int n,m,a[2005],num[2005],ans;
void dfs(int p,int last){
	if(p>m){
		int sum=num[1];
		for(int i=1;i<=m;i++)
			sum=sum&num[i];
		ans=max(sum,ans);
		return;
	}
	for(int i=last+1;i<=n;i++){
		num[p]=a[i];
		dfs(p+1,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n>2000) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	if(n<=20) dfs(1,0);
	else{
		ans=a[1];
		if(m==1) 
			for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		if(m==n)
			for(int i=1;i<=n;i++) ans=ans&a[i];
		if(m==2)
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					ans=max(ans,a[i]&a[j]);
	}	
	cout<<ans;
	return 0;
}