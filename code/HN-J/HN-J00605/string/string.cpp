#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,m=0,x=0,y=0;
	string a,b;
	char x2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>x2;
		m+=x;
		for(int l=1;l<=x;l++){
			a=a+x2;
		}
	}
	for(int i=0;i<m;i++){
		b[i]=a[m-1-i];
		if(b[i]!=a[i])y++;
	}
	y/=2;
	cout<<y;
	return 0;
}
