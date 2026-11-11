#include<bits/stdc++.h>
using namespace std;
int a[200005],p,n,m,dp[20005][20005],s,ans;

void f(int y,int x,int v){
	if(x==0){
		ans=max(ans,v);
		return;
	}
	if(y+x-1>n || v==0)return;
	f(y+1,x-1,v&a[y]);
	f(y+1,x,v);
}

void burst(){
	for(int i=1;i<=n;i++){
		f(i,m,a[i]);
	}
	return;
	
}

void s1(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	return;
	
}

void s2(){
	
	for(int i=1;i<=n;i++){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	
	return;
	
}


int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		s1();
	}else{
		burst();
	}
	
	
	
	
	cout << ans;
	return 0;
} 
