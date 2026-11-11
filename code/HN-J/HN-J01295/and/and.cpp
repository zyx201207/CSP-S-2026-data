#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int z=-1;
		for(int i=0;i<n;i++){
			if(a[i]>z){
				z=a[i];
			}
		}
		cout<<z;
	}
	if(m==n){
		int z=a[0];
		for(int i=1;i<n;i++){
			z=z&a[i];
		}
		cout<<z;
	}
	return 0;
}
