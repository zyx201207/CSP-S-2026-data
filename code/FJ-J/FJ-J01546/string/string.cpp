#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,x=0,y=0;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		m+=a[i];
	}
	char c[m];
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			c[x]=b[i];
			x++;
		}
	}
	for(int i=0;i<m/2;i++) {
		if(c[m/2+i]!=c[m/2-i]){
			y++;
		}
	}
	cout<<y;
	return 0;
}
