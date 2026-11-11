#include<bits/stdc++.h>
using namespace std;
struct t{
	int l=0;
	char c=0;
}*arr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char b;
	cin>>n;
	arr=new t[n];
	for(int i=0;i<n;++i){
		cin>>a>>b;
		arr[i].l=a;
		arr[i].c=b;
	}
	a=0;
	t l,r;
	l=arr[0];
	r=arr[n-1];
	for(int lp=0,rp=n-1;lp<rp;){
		int x=min(l.l,r.l);
		if(l.c!=r.c)a+=x;
		l.l-=x;
		r.l-=x;
		if(l.l==0)l=arr[++lp];
		if(r.l==0)r=arr[--rp];
	}
	delete[]arr;
	cout<<a;
	return 0;
}
