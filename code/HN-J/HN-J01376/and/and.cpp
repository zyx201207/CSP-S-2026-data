#include<bits/stdc++.h>
using namespace std;
#define int long long

unsigned long long a[200005];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
//	int maxn;
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			
//		}
//	}
	
	int p=a[n],q=a[n-1];
	p&=q;
	cout<<p;
	return 0;
}
