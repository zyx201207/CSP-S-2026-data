#include <bits/stdc++.h>
using namespace std;

	long long n,m,a[100000005],k;
int main(){
	//freopen("subway.in","r",stdin); 
	//freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		k=min(a[i],a[i+1]);
	}
	
	cout<<k;
	return 0;
}
