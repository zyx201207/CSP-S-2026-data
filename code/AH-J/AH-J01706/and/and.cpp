#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],c[200005],d,f;
int ws(int p)
{
	int w=0;
	while(p>0){
		w++;
		p/=2;
		
	}
	return w;
}
int wy(int y){
	for(int i=1;i<m;i++){
		a[y]=(a[y]&a[y-i]);
	}
	return a[y];
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=ws(a[i]);	
	}
	for(int i=1;i<=n;i++){
		c[b[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(c[b[i]]>=m){
			d=wy(i);
			f=1;
			break;
		}
	}
	if(f==0)d=wy(n);
	cout<<d;
	return 0;
 } 
