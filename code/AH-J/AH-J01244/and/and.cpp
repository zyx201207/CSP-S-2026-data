#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,m;
	long long a[200010];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int z=a[n-1];
	for(int i=n-2;i>=n-m;i--){
		int y=z & a[i];
		if(y == 0){
			continue;
		}
		z=y;
	}
	cout<<z;
	return 0;
}
