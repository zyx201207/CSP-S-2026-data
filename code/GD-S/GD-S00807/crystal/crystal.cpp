#include<bits/stdc++.h>
using namespace std;
int a[500005] = {};
int b[500005] = {};
int n,m,ans;
int js(int i,int j){
	int num = j-i+1;
	int s = num*a[j]-(b[j]-b[i-1]);
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}sort(a,a+n+1);
//	for(int i = 0;i<=n;i++){
//		cout<<a[i];
//	}
	int before = a[1];
	int now;
	for(int i = 2;i<=n;i++){
		now = a[i];
		a[i] = now-before;
		before = now;
	}a[0] = 0;
	a[1] = 0;
	for(int i = 1;i<=n;i++){
		a[i]+=a[i-1];
	}for(int i = 1;i<=n;i++){
		b[i] = a[i]+b[i-1];
	}
	ans = 1;
//	for(int i = 1;i<n;i++){
//		for(int j = i+1;j<=n;j++){
//			if(js(i,j)<=m) ans = max(ans,j-i+1);
//		}
//	}
	for(int i = 1;i<n;i++){
		for(int j = n;j>=i+ans;j--){
			if(js(i,j)<=m) ans = max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
} 
