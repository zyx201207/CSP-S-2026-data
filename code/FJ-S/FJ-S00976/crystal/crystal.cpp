#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],b[500001],s[500001];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
//				cout<<a[i]*(i-mid+1)-(s[i]-s[mid-1])<<" "
//				<<a[i]*(i-mid+1)<<" "<<(s[0])<<" "<<endl;
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		maxn=max(maxn,i-ans+1);
	}
	cout<<maxn;
	return 0;
}
//miao ~
//++ RP
//RP ++
//100 pts
//All 100 pts
//FJ-J01191 FJ-S00976
