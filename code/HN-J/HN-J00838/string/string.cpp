#include<bits/stdc++.h>
using namespace std;
long long z,k;
long long x=0,y;
struct lll{
	long long n;
	char m;
}a[100005];
void f(int xx,int yy) {
	if(xx==yy)
		return ;
	if(a[xx].m==a[yy].m)
		f(xx+1,yy-1);
	else
	{
		int xy=min(xx,yy);
		k+=a[xy].n;
	}
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>z;
	y=z-1;
	for(int i=0;i<z;i++) {
		cin>>a[i].n>>a[i].m;
	}
	f(x,y);
	cout<<k;
	return 0;
}
