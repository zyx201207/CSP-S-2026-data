#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005];
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int maxx=-9999;
	for(int i=1;i<=n;i++){
		int m1;
		int f=a[i];
		m1 = f & a[i+1];
		for(int j=i;j<=i+m-1;j++){
			m1=m1 & a[j];
		}
		maxx=max(maxx,m1);
	}
	cout<<maxx;
} 
