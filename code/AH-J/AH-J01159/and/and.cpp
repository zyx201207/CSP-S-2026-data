#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0;
	int a[n];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ma=0;	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			ma=max(a[i] & a[j] , ma);
		}
	}
	cout<<ma;
	return 0;
}
