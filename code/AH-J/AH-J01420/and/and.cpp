#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000001];
int f[2000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=m;j>=a[i];j--){
			f[j]=max(f[j],f[j-1]&a[j]);
		}
	}	
	cout<<f[m];
	return 0;
}
