#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n-m;j++){
			int x;
			for(int k=1;k<m;k++){
				x=a[j+k-1]&a[j+k];
			}
			maxx=max(maxx,x);
		}
	}
	cout<<maxx;
	return 0;
}
