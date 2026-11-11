#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int q[n+5];
	string w[n+5];
	int z=0;
	for(int i=1;i<=n;i++){
		cin>>q[i]>>w[i];
		z+=q[i];
	}
	int m=1;
	string a[z+5],b[z+5];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=q[i];j++){
			a[m]=w[i];
			m++;
		}
	}
	int l=0;
	for(int i=m;i>=1;i--){
		b[i]=a[m-i-1];
	}
	for(int i=1;i<=m-1;i++){
		if(a[i]!=b[i]){
			l++;
		}
	}
	cout<<l-1;
	return 0;
}
