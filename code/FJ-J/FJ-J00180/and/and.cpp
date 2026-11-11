#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int s=0,r=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k=m;
		while(k--){
			a[i]=a[i]&a[r];
			r++;
		}
		s=max(s,a[i]);
	}
	cout<<s;
	return 0;
} 
