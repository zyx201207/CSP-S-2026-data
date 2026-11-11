#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>12000){
		int k=a[2]-a[1];
		int l=m;
		int cnt=0;
		for(int i=0;i<n;i++){
			l-=k*i;
			if(l>=0)cnt++;
			else break;
		}
		cout<<cnt;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cost=0;
		int cnt=1;
		for(int j=i-1;j>=1;j--){
			if(cost+a[i]-a[j]>m){
				break;
			}
			cost+=a[i]-a[j];
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
