#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],i,j;
bool b[200005];
long long f(long long x,long long c){
	if(x==0)return c;
	int hi=n;
	while(hi--)if(!b[hi]){
		b[hi]=1;
		return f(x-1,c&a[hi]);
		b[hi]=0;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[n-1];i=n-1;j=a[n-1];
	while(i--){
		cin>>a[i];j=(j&a[i]);
	}sort(a,a+n);
	if(m==n)cout<<j;
	cout<<f(m,a[n-1]);
	return 0;
}
