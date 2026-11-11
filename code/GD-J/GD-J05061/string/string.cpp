#include<bits/stdc++.h>
using namespace std;
int n,x,ans;
string a,c;
char b;
int qwe=0,si;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>b;
		for(int j=1;j<=x;j++){
			a[qwe]=b;
			qwe++;
		}
	}
	si=qwe/2;
	for(int i=0;i<si;i++)
		c[i]=a[i];
	if(qwe%2!=0)si++;
	for(int i=si,j=0;i<qwe;i++,j++)
		if(a[i]!=a[j]) ans++;
	cout<<ans;
return 0;}
