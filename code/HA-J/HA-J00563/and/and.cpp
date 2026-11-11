#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int zuida=0;
	int n,m;
	cin>>n>>m;
	int yu=0;
	int a[101]={};
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int l=i+1;l<n;l++){
			if (a[i]<a[l]){
				swap(a[i],a[l]);
			}
		}
	}
	yu=a[0]&a[1];
	for (int i=2;i<m;i++){
		yu=yu&a[i];
	}
	cout<<yu<<"\n";
	return 0;
}
