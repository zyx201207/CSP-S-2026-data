// GZ-J00033 ºÎçâå· 
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int bj[100005];
int n;
int dfs(int dq,int c){
	int maxn=0;
	int ans=1;
	if(c==0){
		return dq;
	}
	bj[dq]=1;
	for(int i=1;i<=n;i++){
		if(!bj[a[i]]){
			maxn=max(maxn,dfs(a[i],c-1));
		}
	}
	bj[dq]=0;
	return ans&maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	int m;
	cin>>m;
	int maxn=0;
	int ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else if(m==n){
		cout<<ans;
		return 0;
	}
	else if(m==2&&n<=2000){
		int ans1=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else{
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,dfs(a[i],m));
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
