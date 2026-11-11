#include<bits/stdc++.h>
using namespace std;
string x,y;
long long n,z,z1;
struct f1{
	long long x;
	char y;
};
f1 f[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		long long m;
		char b;
		cin >> m >> b;
		f[i].x=m;
		f[i].y=b;
		z+=m;
	}
	long long c=1,c1=1;
	for(long long i=1;i<=z/2;i++){
		if(c>f[c1].x)c1++,c=1;
		x[i]=f[c1].y;
		c++;
	}
	if(c>f[c1].x)c1++,c=1;
	if(z%2!=0)c++;
	for(long long i=1;i<=z/2;i++){
		if(c>f[c1].x)c1++,c=1;
		y[i]=f[c1].y;
		c++;
	}
	for(long long i=1,j=z/2;i<=z/2;i++,j--){
		if(x[i]!=y[j])z1++;
	}
	cout << z1;
	return 0;
}
