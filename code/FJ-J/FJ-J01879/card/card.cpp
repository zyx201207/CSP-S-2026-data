#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=1;
	cin >> n >> m;
	int a[n],k[100000*5+1]={};
	cin>>a[0];
	for(int i=1; i<n; i++){
		cin >> a[i];
		if(a[i-1]>=a[i])f=0;
	}
	if(f){
		for(int i=0; i<=m; i++){
			cout<<1+i;
			if(i<m)cout<<" ";
		}
	}
	else if(m==1){
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
