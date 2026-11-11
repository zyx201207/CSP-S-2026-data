#include<bits/stdc++.h> 
using namespace std;
int a[500005],n,m,ans;
void dfs(int t,int sum,int s){
	if(s==m){
		if(sum>ans){
			ans=sum;
			return;
		}
		return;
	}
	for(int i=t;i<=n;i++){
		if(t==1){
			sum=a[i];
			s--;
		}
		t++;
		s++;
		dfs(t,sum&a[i],s);
		t--;
		s--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
