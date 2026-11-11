#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		if(a[j]<m){
			a[j]++;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
