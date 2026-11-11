//S组T1做出来了，意满离 
#include<bits/stdc++.h>//二分答案？ 
using namespace std;
int n;
long long m; 
long long a[500005],s[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		bool f=0;
		for(int i=1;i+mid-1<=n;i++){
			int j=i+mid-1;
			if(a[j]*mid-(s[j]-s[i-1])<=m){
				f=1;
				break;
			}
		}
		if(f)l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
