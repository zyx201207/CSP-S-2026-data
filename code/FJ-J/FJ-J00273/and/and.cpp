#include<bits/stdc++.h>
using namespace std;
long long a[100005],zd;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			zd=max(zd,a[i]&a[j]);
		}
	}
	cout<<zd;
	return 0;
} 
