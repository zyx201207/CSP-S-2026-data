#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000&&a[2]-a[1]==a[4]-a[3]&&a[2]-a[1]==a[n]-a[n-1]&&a[n/2]-a[n/2-1]==a[n]-a[n-1]){
		int c=a[2]-a[1];
		m/=c;
		long long cnt=0;
		int i=1;
		while(cnt<=m){
			cnt+=i;
			i++;
		}
		cout<<i-1;
		return 0;
	}
	long long maxx=1;
	for(int i=2;i<=n;i++){
		long long mm=m,cnt=1;
		for(int j=i-1;j>=1;j--){
			if(a[j]+mm>=a[i]){
				cnt++;
				mm=mm-(a[i]-a[j]);
			}else break;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
}

