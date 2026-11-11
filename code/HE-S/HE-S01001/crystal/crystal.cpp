#include<bits/stdc++.h>
using namespace std;
long long n,m,a[511111],b[11580][11580],ans[511111],f;
int main(){
	freopen("crystal.in","r+",stdin);
	freopen("crystal.out","r+",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<n;j++){
			b[i][j]=a[i]-a[j];
		}
	}
	f=m;
	for(long long i=2;i<=n;i++){
		for(long long j=1;j<n;j++){
			if(m>=b[i][j]){
				m-=b[i][j];
				ans[i]++;
			}else{
				break;
			}
		}
		m=f;
	}
	sort(ans+2,ans+n+1);
	cout<<ans[n];
	return 0;
}
