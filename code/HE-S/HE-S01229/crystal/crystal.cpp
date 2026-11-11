#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m; 
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int t=n-n/2-1;
	for(int i=0;i<n;++i){
		if(a[i]<a[t]){
			if(m>=a[t]-a[i]){
				a[i]=a[t];
				m-=a[t]-a[i];
			}
		}
	}
	long long sum=0;
	for(int i=0;i<n;++i){
		if(a[i]==a[t]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
