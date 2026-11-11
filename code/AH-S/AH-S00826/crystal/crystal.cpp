#include<bits/stdc++.h>
using namespace std;
long long a[500005];
bool cmp (long long p,long long q){
	return p<q;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort (a+1,a+n+1,cmp);
	if (n<=5000){
		long long fans=0;
		for (int i=1;i<=n;i++){
			long long ans=0,h=m;
			for (int j=i;j>=1;j--){
				h-=a[i]-a[j];
				if (h>=0) ans++;
				else break;
			}
			fans=max(fans,ans);
		}
		cout<<fans<<"\n";
	}
	else {
		long long ans=0;
		while (ans<n){
			m-=ans*(a[ans+1]-a[ans]);
			if (m>=0) ans++;
			else break;
		}
		for (long long i=ans+1;i<=n;i++){
			if (a[i]==a[i-1]) ans++;
			else break; 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
