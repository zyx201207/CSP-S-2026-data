#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long n,m,cnt=0,sum=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0,j=0;i<n;i++){
		if(i!=0)sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[j]);
			j++;
		}
		cnt=max(cnt,i-j+1);
	}
	cout<<cnt;
	return 0;
}
