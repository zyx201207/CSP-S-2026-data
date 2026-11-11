#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,max=0;
	cin>>n>>m;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	cout<<c[n-m];
	return 0;
}

