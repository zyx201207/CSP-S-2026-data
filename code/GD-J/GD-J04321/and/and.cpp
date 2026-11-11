#include<bits/stdc++.h>
using namespace std;

int ans,n,m,a[200005],d[200005]={0b1111111111111111111111111111111},l[200005];

void dfs(int i){
	if(i>m){
		ans=max(ans,d[m]);
		return;
	}
	for(int k=i;k<=n-(m-i);k++){
		if(!l[k]){
			d[i]=d[i-1]&a[k];
			l[k]=1;
			dfs(i+1);
			l[k]=0;
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)ans=0;
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
	}
	else dfs(1);
	cout<<ans;
}
