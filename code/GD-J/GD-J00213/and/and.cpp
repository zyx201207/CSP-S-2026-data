#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long x,y;
	cin>>x>>y;
	for(int i=0;i<x;i++){
		cin>>a[i];
	}
	cout<<a[x-1];
	return 0;
} 
