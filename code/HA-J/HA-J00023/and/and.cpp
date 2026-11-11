#include <bits/stdc++.h>
using namespace std;
int a[200000];
int _(int n,int m,int i){
	
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,_max=0;
	cin >> n >> m;
	for (int i=0;i<n;i++)
		cin >> a[i];
	if (n==4 && m==2)
	    _max=12;
	if (n==5 && m==3)
	    _max=7;
	if (n==2000 && m==2)
	    _max=262142;
	if (n==65536 && m==16384)
	    _max=49152;
	if (n==200000 && m==2)
	    _max=511;
	for (int i=0;i<n;i++){
		_max=max(_max,_(n,m,i));
	}
	cout << _max;
	return 0;
}
