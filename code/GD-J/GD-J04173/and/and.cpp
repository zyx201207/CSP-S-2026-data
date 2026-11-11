#include<bits/stdc++.h>
using namespace std;
int n,a[200001],m,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>mx){
				mx=a[i]&a[j];
			}
		}
	}
	cout<<mx;
	return 0;
}
