#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r");
	//freopen("and.out"."w");
	int n,m,zd,andi=0;
	cin>>n>>m;
	int sz[n];
	for(int i=0;i<n;i++){
		cin>>sz[i];
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			andi=sz[i] and sz[j];
			if(andi>zd)
				zd=andi;
			}
		}
	cout<<zd;
	return 0;
	}
