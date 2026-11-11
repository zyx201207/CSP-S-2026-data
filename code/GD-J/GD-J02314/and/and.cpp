#include <bits/stdc++.h>
using namespace std;

long long n,m,mx=INT_MIN,sum;
long long a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<n-1;j++){
			sum+=a[i]&a[j+1];
		}
		mx=max(sum,mx);
		sum=0;
	}
	cout<<mx;
	
	return 0;
} 
