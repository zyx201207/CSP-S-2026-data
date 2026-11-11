#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1],ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]<a[i+1]){
			a[i]++;
			}
			if(a[i]==a[i+1]){
				ans++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
