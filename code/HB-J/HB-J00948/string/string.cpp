#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,sum,f;
struct node{
	char c;
	long long x;
}a[200001];//Trick||Treat!
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
	while(l<r){
		f=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c) sum+=f;
		a[l].x-=f;
		a[r].x-=f;
		if(a[l].x==0) l++;
		if(a[r].x==0) r--;
	}
	cout<<sum;
	return 0;
}
