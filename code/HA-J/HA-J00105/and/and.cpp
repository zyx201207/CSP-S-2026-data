#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		
	int n,m,o=0;
	long long a[n+1];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]^a[i+1]>o){
			o=a[i]^a[i+1];
		}
	}
	cout<<o;

	return 0;	
}
