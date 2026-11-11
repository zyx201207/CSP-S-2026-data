#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m,a[500009];
	cin>>n>>m;
	int ans[n][m];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]==a[j])i+=j;
		}
	}
	cout<<0;
	
	return 0;
}
