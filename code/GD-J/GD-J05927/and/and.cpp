#include<bits/stdc++.h>
using namespace std;
int mmx(int aa[600000000]={})
{
	int nn = aa.size();
	int d = 0;
	int m = 0;
	for(int i = 0;i<nn;i++){
		if (aa[i]>d){
			d = aa[i];
			m = i;
		}
		
	}
	a[m] =-1;
	return d;
}
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,da[10000000]={};
	cin>> n>>m;
	int a[100000000] ={};
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	for(int i =0;i<m;i++){
		a[i] = mmx(da);
	}
	int z = 0;
	for(int i =0;i<m;i++){
		z += a[i] ;
	}
	cout<<z;
	return 0;
	
}
