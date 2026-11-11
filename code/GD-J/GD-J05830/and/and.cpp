#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	} 
	sort(a+1,a+1+n);
	int ans=0;
	for(int j=n;j>1;j--){
		int sum=a[j];
		for(int i=2;i<=m;i++){
			sum=sum&a[n-i];
		}
		ans=max(ans,sum);
	}
	
	cout<<ans;
} 
