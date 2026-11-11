#include<bits/stdc++.h>
using namespace std;
long long n,m,j,b;
long long a[99999999];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int minn;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		j=a[i+1]-a[i];
	}
	j=abs(j);
	for(int i=1;i<=m;i++){
		if(a[0]+j==a[i]) b++;
	}
	if(n==m) cout<<b+2;
	else if(n<m) cout<<b+3;
	return 0;
}
