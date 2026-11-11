#include<bits/stdc++.h>
using namespace std;
struct q{
	long long b;
	char s;
} a[201010];
long long z;
int n;
void c(int l,int r){
	if(l==r||l>r) return ;
	long long u=min(a[l].b,a[r].b);
	if(a[l].s!=a[r].s) z+=u;
	a[l].b-=u;
	a[r].b-=u;
	if(a[l].b==0) l++;
	if(a[r].b==0) r--;
	c(l,r);
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i].b>>a[i].s;
	c(1,n);
	cout<<z;
	return 0;
} 
