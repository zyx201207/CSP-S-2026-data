#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=0,b;
long long a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			
			
			mx=max(a[i],a[j]);
		}
			}
	cout<<a[n];
	return 0;
}
