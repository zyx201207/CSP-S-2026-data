#include<bits/stdc++.h>
using namespace std;

long long n,m,c[500001],maxans=0;

bool cmp(long long a,long long b){
	return a>b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n,cmp);
	long long ans=0;
	long long s=0;
	for(long long j=0;j<n;j++){
		if(c[0]-c[j]<=m){
			m-=c[0]-c[j];
			ans++;
			s++;
		} else {break;}
	}
	maxans=ans;
	for(long long i=1;i<n;i++){
		m=m+(ans-1)*(c[i-1]-c[i]);
		ans--;
		for(;s<n;){
			if(m>=c[i]-c[s]){
				m-=c[i]-c[s];
				ans++;
				s++;
			} else {break;}
		}
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}
