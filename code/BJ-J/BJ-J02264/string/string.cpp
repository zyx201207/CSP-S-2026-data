#include<bits/stdc++.h>
using namespace std;
struct z{
	long long q;
	string w;
};
int main(){
	freopen("std.in","r",stdin);
	freopen("std.out","w",stdout);
	long long n,m=1,x=1,v=1;
	cin>>n;
	z a[n];
	for(long long i=0;i<n;i++){
		cin>>a[i].q>>a[i].w;
		v+=a[i].q;
		if(i!=0&&a[i].w==a[i-1].w)
			m++;
		if(i!=0&&a[i].w!=a[i-1].w)
			x++;
	}
	if(m==n)
		cout<<"0";
	if(x>26)
		x=26;
	else
		cout<<v/x;
	return 0;
}
