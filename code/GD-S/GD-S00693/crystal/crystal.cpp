#include<bits/stdc++.h>
using namespace std;

long long n,m;

long long a[200005];

long long sum=0; 

long long c[200005];
long long d[200005];


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int r=1,l=1;
	int ans=0;
	for(int i=1;i<n;i++){
		sum+=i*(a[i+1]-a[i]);
		l++;
		while(sum>m){
			sum-=a[l]-a[r];	
			r++;
		}
		ans=max(ans,l-r+1);
	}
	cout<<ans;
	return 0;
} 
