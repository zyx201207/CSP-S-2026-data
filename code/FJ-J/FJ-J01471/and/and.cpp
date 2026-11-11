#include<bits/stdc++.h>
#include<string>
using namespace std;
int a[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l=0,p=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=i;j++){
		    for(int z=1;z<=m-1;z++){
		    	if(a[i]!=a[j]||i!=j){
		    	p=a[i];
		    	p=p&a[j];}
			}
			l=max(p,l);
		}
	}
	cout<<l;
	return 0;
} 
