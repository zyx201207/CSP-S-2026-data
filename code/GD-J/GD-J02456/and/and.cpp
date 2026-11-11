#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0,c=1000000000;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>b)
			b=a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]<c)
			c=a[i];
	}
	cout<<(b&c);
	return 0;
}
