#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	int A=0,B=0,C=0,D=0;
	if(n==m){
		A=1;
	}
	if(a[0]==b[0]&&a[1]==b[1]&&n==m){
		B=1;
	}
	if((a[0]==b[0]&&a[1]==b[1]&&n==m&&a[2]<='C'&&b[2]<='C')||(a[0]==b[0]&&a[1]==b[1]&&n==m&&a[2]>='D'&&b[2]>='D')){
		C=1;
			}
	if(a[0]=b[0]&&a[1]==b[1]&&abs(a[2]-b[2])==1){
		D=1;
		if(D==1&&a[2]=='D'&&b[2]=='C'||D==1&&a[2]=='C'&&b[2]=='D'){
			D=0;
		}
	}
	cout<<A<<B<<C<<D;
	return 0;
}
