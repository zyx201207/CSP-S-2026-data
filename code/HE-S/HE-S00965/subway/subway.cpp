#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
int main(){
	
	cin>>c>>n>>m>>d>>p;
	int w[100005];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	long long a[100005];
	for(int i=0;i<n;i++){
		int e;
		cin>>e;
		for(int j=0;j<e;j++){
			cin>>a[j];
		}
	}
	
	for(int i=0;i<p;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x-1]+w[y-1]+2*(y-x)*a[1];
	}
	return 0;
} 
