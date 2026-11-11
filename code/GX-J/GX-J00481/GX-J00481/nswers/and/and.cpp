#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b1,b2=0;
		b[i]=max(b[i],b2);
		for(int j=1;j<=n;j++){
			b2=max(b1,b2);
			for(int x=1;x<=m;j++){
				b1=a[i]&a[j+x];			
	}}}
	long long B=0;
	for (int i=1;i<=n;i++)
		B=max(B,b[i]);
	cout<<B;
	
	return 0;
}
