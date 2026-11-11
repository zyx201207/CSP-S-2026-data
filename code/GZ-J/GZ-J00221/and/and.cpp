//GZ-J00221  ¿Ó È∫≠
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n;
int m;
int a[N];
long long ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);

	cout<<a[n-2];
	return 0;
}
