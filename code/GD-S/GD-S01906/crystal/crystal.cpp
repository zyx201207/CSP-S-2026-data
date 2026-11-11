#include <bits/stdc++.h>
using namespace std;
long long a[500005]; 
long long dis[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	long long m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	long long mid=ans/n;
	sort(a+1,a+n+1);
	long long maxn=-1;
	for(int i=n;i>=maxn;i--){
		if(a[i]==a[i+1]) continue;
		long long cnt=0,m1=m;
		for(int j=i;j>=1;j--){
			dis[j]=abs(a[i]-a[j]);
			if(dis[j]<=m1){
				m1-=dis[j];
				cnt++;
			}
			else break;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}

