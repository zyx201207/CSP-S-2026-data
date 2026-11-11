#include<bits/stdc++.h>
using namespace std;
int n,m,a[214514],maxx=-1;
int dfs(int last){
	int max=-1;
	for(int i=last+1;i<=n;i++){
		int ans=a[i]&dfs(i);
		if(ans>max){
			max=ans;
		}
	}
	return max;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(pow(n,m)<=150000000){
		cout<<dfs(0);
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(i==j)continue;
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else if(n==m){
		maxx=a[1];
		for(int i=2;i<=n;i++){
			maxx=maxx&a[i];
		}
		cout<<maxx;
	}
	else if(n==m+1){
		int t;
		for(int i=1;i<=n;i++){
			if(i!=1)t=a[1];
			else t=a[2];
			for(int j=2;j<=n;j++){
				if(j==i)continue;
				t=t&a[i];
			}
			maxx=max(maxx,t);
		}
		cout<<maxx;
	}
	else{
		sort(a+1,a+1+n);
		int t=a[n];
		for(int i=2;i<=m;i++){
			t=t&a[n-i];
		}
		cout<<t;
	}
	return 0;
}
