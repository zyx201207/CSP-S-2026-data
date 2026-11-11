#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long sum=0,go=0;
	long long maxn=0,ans=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			sum+=a[i]-a[j];
			if(sum>m){
				sum-=a[i]-a[go];go++;
			}
			ans=i-go+1;
		}
		maxn=max(maxn,ans);
		sum=0;
	}
	cout<<maxn;
	return 0;
} 
