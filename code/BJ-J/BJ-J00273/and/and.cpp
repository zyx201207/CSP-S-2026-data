#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=a[1];
	if(n==m){
		for(int i=2;i<=n;i++){
			k=k&a[i];
		}
		cout<<k;
		return 0;
	}
	sort(a+1,a+n+1);
	do{
		k=a[1];
		for(int i=1;i<=m;i++){
			k=k&a[i];
		}
		ma=max(ma,k);
	}while(next_permutation(a+1,a+n+1));
	cout<<ma;
	return 0;
}
