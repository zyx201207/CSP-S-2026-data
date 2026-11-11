#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long ans,cnt;
long long a[N];
void dfs(int i,long long val,int num,int f){
	if(num==0){
		ans=max(ans,val);
		return ;
	}
	if(i>n||i+num-1>n) return ;
	dfs(i+1,val,num,f);
	if(m>0){
		if(f==0) dfs(i+1,a[i],num-1,1);
		else dfs(i+1,a[i]&val,num-1,1);
	} 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<i<<" ";
	} 
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			cnt=a[i];
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,cnt&a[j]); 
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,m,0);
	cout<<ans;
	
	
	return 0;
}

