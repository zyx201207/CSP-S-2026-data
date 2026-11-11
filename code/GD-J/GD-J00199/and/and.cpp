#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002];
 long long k=0,g=0,f,z,p=1,x[1000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;f=n;
	if(m==1){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=30;i++){
		x[i]=p;p*=2;
	}
	while(f>1){
		f/=2;k++;
	}
z=m;for(int i=1;i<=30;i++){
	if(z>=x[i]&&z<x[i+1]){
		g=i+1;cout<<n-g;return 0;
	}
}

	 sort(a+1,a+n+1);
	 
 {cout<<a[m];return 0;}
	
	return 0;
}
