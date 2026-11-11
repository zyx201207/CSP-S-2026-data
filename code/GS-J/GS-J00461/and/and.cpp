#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005];
int m,n,i,p,q,w;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+i+1);
		for(p=0;q<=a[i];p++)
			q+=(p*2)*p;
		if(b[p]&&b[p+1])
			w=2*w;
			w++;
		c[p]+=2*w;
	sort(c+1,c+p+1);
	cout<<c[p];
		return 0;
}
