#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	long long l=0,r=-1;
	long long ans=0,cost=0,cnt=0;
	while(r+1<n){
		r++;
		cnt+=a[r];
		cost=a[r]*(r-l+1)-cnt;
		if(cost<=m) ans=max(ans,r-l+1);
		else{
			while(cost>m&&l<=r){
				cnt-=a[l];
				cost=a[r]*(r-l+1)-cnt;
				l++;
			}
		}
	}
	cout<<ans;
 } 
