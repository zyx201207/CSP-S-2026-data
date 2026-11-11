#include <bits/stdc++.h>
using namespace std;
int x[100005],m;
char y[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,k=0;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int z;
		cin>>z>>y[i];
		x[i]=z;
		n+=z;
	}
	n-=1;
	long long l=0-1,r=n+1,qr=m,ql=1;
	while(l!=r&&l+1!=r)
	{
		l++;
		r--;
		if(x[ql]==0)
			ql++;
		if(x[qr]==0)
			qr--;
		x[ql]--;
		x[qr]--;
		if(y[ql]!=y[qr])
		    k++;
	}
	cout<<k;
	return 0;
}
