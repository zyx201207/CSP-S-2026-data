#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m,m1,ans,maxn;
bool ok=0;
int main(){
	cin.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(ok==1){
			ok=0;
		}
		if(a[i]==i){
			ok=1;
		}
	}
	if(ok){
		for(long long i=n;i>=1;i--){
			if(m1<m && a[n]-a[i-1]<=m-m1){
				m1=a[n]-a[i-1];
				maxn++;
			}else{
				break;
			}
		}
	}else{
		sort(a+1,a+n+1);             
		for(long long i=1;i<=n;i++){
			m1=0;
			for(long long j=i;j>=1;j--){
				if(a[i]-a[j]<=m-m1){
					m1+=a[i]-a[j];
					ans++;
				}
			}
			maxn=max(ans,maxn);
			ans=0;
		}
	}
	cout<<maxn;
	return 0;
}
