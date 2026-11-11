//GZ-J00054 ÀÔ–°∫≠ 
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long s=a[1];
	for(int i=2;i<=n;i++){
		s=(s&a[i]);
	}
	cout<<s;
	return 0;
} 
