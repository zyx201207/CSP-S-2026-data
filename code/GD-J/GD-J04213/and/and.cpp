#include <bits/stdc++.h>
using namespace std;
int n,m,a[2005],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==n){
		int s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		cout<<s;
	}
	else if(n==1) cout<<maxn;
	else {
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	
	return 0;
}
