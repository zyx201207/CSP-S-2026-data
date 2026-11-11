#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=1,aum=-1;
	for(long long i = 1;i<=n;i++){
		int t=m;
		for(long long j = 1;j<=n;j++){
			if(i!=j){
				if(a[j]==a[i])
					ans++;
				else if(a[j]<a[i]&&a[i]-a[j]<=t){
					ans++;
					t=t-(a[i]-a[j]);
				}	
				else
					break;
			}
		}
		aum=max(aum,ans);
		ans=1;
	}
	cout<<aum;
	return 0;
} 
