#include<bits/stdc++.h>
using namespace std;
int s[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	cout<<s[n-m+1];
	return 0;
} 
