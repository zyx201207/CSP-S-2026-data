#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,cnt,maxn=1;
	long long m,m0,a[500001],b[500001]={};
	bool f=1;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(i!=2&&b[i]!=b[i-1]){
			f=0;
		}
	}
	if(f){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(sum>m){
				cout<<i-1;
				return 0;
			}
			sum+=(i*b[n]);
		}
		cout<<n;
		return 0;
	}
	stable_sort(a+1,a+n+1);
	for(int i=n;i>maxn&&i>=1;i--){
		m0=m;
		cnt=1;
		for(int j=i-1;j>=0;j--){
			if(a[i]-a[j]>m0){
				break;
			}
			m0-=(a[i]-a[j]);
			cnt++;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
} 
