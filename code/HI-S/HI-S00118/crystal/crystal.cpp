#include<bits/stdc++.h>
using namespace std;
long long n;
long long m,sum;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	sum+=m;
	sum/=n;
	int q=0;
	for(int i=1;i<=n&&a[i]<=sum;i++){
		q=i;
	}
	int cnt=0;
	for(int k=1;k<=n;k++){
		int w=0;
		long long h=m;
		for(int i=k;i>=1&&h>=a[k]-a[i];i--){
			h=h-a[k]+a[i];
			w++;
		}
		cnt=max(cnt,w);
	}
	cout<<cnt;
	return 0;
}
