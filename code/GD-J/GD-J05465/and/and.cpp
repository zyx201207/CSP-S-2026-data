#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m,a[N],maxx=-2e5,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			for(long long k=i+j;k<=n;k++){
				t=a[i]&a[k];
			}
		}
		maxx=max(maxx,t);
	}
	cout<<maxx;
	return 0;
}
