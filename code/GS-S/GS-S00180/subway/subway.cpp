#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q,z,x,v,b;
	cin>>c>>n>>m>>d>>q;
	int k=0;k=m;
	int l;
	l=1+2*n;
	int w[k];
	int r[l];
	int e[l];
	for(int i=0;i<m;i++){
		cin>>w[i];
	} 
	for(int i=0;i<1+2*n;i++){
		cin>>r[i];
	}
	for(int i=0;i<1+2*n;i++){
		cin>>e[i];
	}
	cin>>z>>x;
	cin>>v>>b;
	cout<<w[1]+r[2]+e[6]+e[0]+r[5]+w[3]<<endl;
	cout<<w[1]+r[2]+e[6]+w[2];
}
