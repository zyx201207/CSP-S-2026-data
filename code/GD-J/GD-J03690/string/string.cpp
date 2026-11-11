#include<bits/stdc++.h>
using namespace std;
struct jj{
	long long b,e;
	char c;
};
jj a[100100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);   
	int n;
	long long l=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i].e>>a[i].c;
		a[i].b=l+1;
		a[i].e+=l;
		l=a[i].e;
	}
	long long be_gin=0,e_nd=n-1;
	long long ans=0;
	while (be_gin<=e_nd){
		long long o=min(a[be_gin].e-a[be_gin].b+1,a[e_nd].e-a[e_nd].b+1);
		if (a[be_gin].c!=a[e_nd].c){
			ans+=o;
		}
		a[be_gin].b+=o;
		a[e_nd].e-=o;
		if (a[be_gin].b+o-1>a[be_gin].e) be_gin++;
		if (a[e_nd].e-o+1<a[e_nd].b) e_nd--;
	}
	cout<<ans;
} 
