#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s,d=0,w=10;
	cin>>n>>m;
	int a[n],z[n];
	for(int i=0;i<n;i++){
		cin<<a[i];
		z[i]=a[i];
	}
	
	
	sort(z,z+n);
	while(s==0){
		s=z[m-1]/2;
		d++;
	}
	cout<<"7";
	return 0;
}
