#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans=0,s1[200005],s2[200005],flag1=1;
void dfs(int x,int now,int k){
	if(k==m){
		ans=max(ans,now);
		return;
	}
	if(x>n){
		return;
	}
	if(now==-1){
		dfs(x+1,a[x],k+1);
		dfs(x+1,-1,k);
	}
	else{
		dfs(x+1,now&a[x],k+1);
		dfs(x+1,now,k);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pow(2,log2(a[i]+1))!=a[i+1]){
			flag1=0;
		}
	}
	if(n<=20){
		dfs(1,-1,0);
		cout<<ans;
		return 0; 
	}
	if(m==1){
		for(int i=1,mx=0;i<=n;i++){
			mx=max(mx,a[i]);
			if(i==n){
				cout<<mx;
			}
		}
		return 0;
	}
	if(m==2){
		for(int i=1,mx=0;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx=max(mx,a[i]&a[j]);
				}
			}
			if(i==n){
				cout<<mx;
			}
		}
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		s1[1]=a[1];
		s2[n]=a[n];
		for(int i=2;i<=n;i++){
			s1[i]=s1[i-1]&a[i];
		}
		for(int i=n-1;i>0;i--){
			s2[i]=s2[i+1]&a[i];
		}
		for(int i=1,mx=0;i<=n;i++){
			mx=max(mx,s1[(i-1==0?n:i-1)]&s2[(i+1>n?1:i+1)]);
			if(i==n){
				cout<<mx;
			}
		}
		return 0;
	}
	if(flag1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	return 0;
}
/*
67 83 80 82 80 43 61 73 78 70
*/
