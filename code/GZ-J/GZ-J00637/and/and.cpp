//GZ-J00637,濮铭希,贵阳市第二十九中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],b[N],ans;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int k=n-1;
	int v=1;
	for(int i=1;i<=m;i++){
		b[i]=a[k];
		k--;	
		cout<<b[i]<<' ';
	}
	cout<<b[m];
	return 0;
}
