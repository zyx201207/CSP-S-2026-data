#include<bits/stdc++.h>
using namespace std;
char u[500005];
int m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	int l=1;
	for(int i=1;i<=m;i++){
		char z;
		int p;
		cin>>p>>z; 
		if(p+l-1>1e7) return 0;
		for(int j=l;j<=p+l-1;j++) u[j]=z;
		l+=p;
	}
	l--;
	int sum=0;
	for(int i=1;i<=l/2;i++) if(u[i]!=u[l-i+1]) sum++;
	cout<<sum;
}
