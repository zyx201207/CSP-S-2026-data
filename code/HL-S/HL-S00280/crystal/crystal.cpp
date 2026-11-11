#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500500],c[500500],d[500500];
long long ss(long long a,long long b){
	long long  i=b-a;
	return i;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>100000000000000){
		long long mm=0;
		long long gc=a[2]-a[1];
		for(int i=2;i<=n;i++){
			mm=gc*i*(i-1)/2;
			if(mm>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1;i<n;i++){
		c[i]=ss(a[i],a[i+1]);
	}
	int cnt=1;
	for(int i=1;i<n-1;i++){
		int ans=0;
		if(c[i]<=m){
			ans=2;
			d[i]=c[i];
			for(int j=i+1;j<n;j++){
				d[j]=d[j-1]+c[j]*(j-i+1);
				if(d[j]<=m){
					ans++;
				}
			}
			cnt=max(cnt,ans);
		}
	}
	int tmax=1;
	for(int i=1;i<n;i++){
		bool t=true;
		int tt=1;
		for(int j=i+1;j<=n;j++){
			if(t=true){
				if(a[i]==a[j]){
					tt++;
				}else{
					t=false;
				}
			}
		}
		tmax=max(tt,tmax);
	}
	cout<<max(tmax,cnt);
	return 0;
}

