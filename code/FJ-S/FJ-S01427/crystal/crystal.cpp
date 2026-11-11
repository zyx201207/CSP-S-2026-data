#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		 cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int z=0;
		for(int j=i-1;j>=1;j--){
			z+=a[i]-a[j];
		}
		if(m<z){
			cout<<i-1;
			return 0;
		}
	} 
	return 0;
}
