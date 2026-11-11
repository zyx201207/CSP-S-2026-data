#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],b[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		c[i]=a[i]*(i-1)-b[i-1];
	}
	int q=n;
	while(q>=1&&c[q]>m)q--;
	cout<<q;
	return 0;
}
