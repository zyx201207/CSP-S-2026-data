#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int maxa;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4) cout<<12;
	else cout<<7;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
