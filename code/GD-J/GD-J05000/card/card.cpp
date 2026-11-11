#include<bits/stdc++.h>
using namespace std;
int a[500000]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,c,b;
	cin>>n>>m;
	c=n;
	b=m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=0;i<100;i++){
		n+=m;
		m-=1;
	}
	cout<<b<<' '<<a[1]<<' '<<c;
	return 0;
}
