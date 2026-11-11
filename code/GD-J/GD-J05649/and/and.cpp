#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,h;
	freopen("and.in","r",stdin);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<m;i++){for(int i=0;i<m;i++){
		h+=a[i];
	}
	}
	freopen("stdout","w",stdout);
	cout<<h;
	fclose stdin;
	fclose stdout;
}









