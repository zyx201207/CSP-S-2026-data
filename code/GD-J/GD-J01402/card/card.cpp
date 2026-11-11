#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
int n,m;
int a[maxn];
int ans[maxn];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==n){
			ans[a[i]]++;
		}else if(i+2==j&&a[i]!=a[i+1]&&a[i+1]!=a[j]){
			ans[a[i+1]]++;
		}
		else{
			for(int j=1;j<=n;i++){
			ans[a[i]]++;
			ans[a[n]]++;
		}
	}

	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	} 
	return 0;
}
