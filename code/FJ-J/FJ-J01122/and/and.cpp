#include <bits/stdc++.h> 
using namespace std;
int n,m,a[100000];
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	return 0;
}

