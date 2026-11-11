#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001];
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1) cout<<a[0];
	if(m==0) cout<<0;
	return 0;
}
