#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=b[i-1]+i*(a[i+1]-a[i]);
	}
	int maxx=0;
	for(int i=n;i>=1;i--){
		if(b[i]==m){
			maxx=i;
			break;
		}
	}
	cout<<maxx+1<<endl;
	return 0;
} 
