#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],x,A,B,ans;
bool b[200001];
int c[5];
void dfs(int w,int count,int z){
	if(w>n)return;
	if(count==m){
		ans=max(ans,z);
		return ;
	}
	for(int i=w+1;i<=n;i++){
		
		dfs(i,count+1,z & (a[i]));
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		if(a[i]<=4)c[a[i]]++;
		if(a[i]!=i-1)B=1;
		x=max(x,a[i]);
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(i,1,a[i]);
		}
		cout<<ans;
	}
	else if(m==1){
		cout<<x;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i] & a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(x<=4){
		if(m<=c[4]){
			ans=4;
		}
		else if(m<=c[3]){
			ans=3;
		}
		else if(m<=c[2]+c[3]){
			ans=2;
		}
		else if(m<=c[1]+c[3]){
			ans=1;
		}
		else{
			ans =0;
		}
		cout<<ans;
	}
	else{
		cout<<int(pow(2,20));
	}
	return 0;
}
