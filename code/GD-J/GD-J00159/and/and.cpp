#include<bits/stdc++.h>
using namespace std;
long long a[1000005],d[2005][2005],n,m,o,p;
char c;
string s,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		o=max(a[i],o);
		if(i==1) p=a[i];
		else p=(p&a[i]);
	}
	if(m==1){
		cout<<o;
		return 0;
	}
	if(m==n){
		cout<<p;
		return 0;
	}
	d[1][1]=a[1];
	for(int i=1;i<=n;i++){
		d[i][1]=max(a[i],d[i-1][1]);
		for(int j=2;j<=m;j++){
			d[i][j]=max(d[i-1][j],(d[i-1][j-1]&a[i]));
		}
	}
	cout<<d[n][m];
	return 0;
}
