#include <bits/stdc++.h>
using namespace std;
int n,m;
int maxx,mami;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int s[n+5];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	int j=n;
	for(int i=1;i<=n;i++){
		if(j==m)cout<<s[i];
		j--;
	}
	return 0;
} 
