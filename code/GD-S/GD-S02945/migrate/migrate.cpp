#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	int t;
	cin>>t;
	int ans[100005];
	
	long long n,h;
	for(int z=1;z<=t;z++){
		memset(a,0,n+1);
		cin>>n>>h;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cnt=0;
		for(int i=1;i<n-2;i++){
			if((a[i+2]-a[i]==h && a[i+3]-a[i+1]<=h)||(a[i+3]-a[i+1]==h && a[i+2]-a[i]<=h)){
				cnt++;
			}
		}
		ans[z]=cnt;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
