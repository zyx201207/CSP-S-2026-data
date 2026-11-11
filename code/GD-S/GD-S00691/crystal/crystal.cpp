#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=0,r=0;
	long long cost=m;
	long long ans=0,cnt=0;
	for (;r<n;r++){
		cost-=(a[r]-a[r-1])*cnt;
		cnt++;
		while (cost<0){
			cost+=a[r]-a[l];
			l++;
			cnt--;
		}
//		cout<<l<<" "<<r<<":"<<cnt<<" "<<cost<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
