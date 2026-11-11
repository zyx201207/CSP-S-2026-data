#include<bits/stdc++.h>
using namespace std;
int m,n,mx=0,a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[i]&a[j]>=mx){
				cout<<(a[i]&a[j])<<' ';
				mx=a[i]&a[j];
			}
		}
	}
	cout<<mx;
	return 0;
}

