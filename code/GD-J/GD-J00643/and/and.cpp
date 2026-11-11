#include<bits/stdc++.h>
using namespace std;
int a[100101];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=max(s,a[i]);
	}
	cout<<s;
	return 0;
}
