#include<bits/stdc++.h>
using namespace std;
int n,maxi;
long long m,sum;
long long a[514514];
int l=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	sum=0;
	for(int i=2;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}maxi=max(maxi,i-l+1); 
	}cout<<maxi;
	return 0;
} 
