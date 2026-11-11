#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],d[500005];//s²î£¬dºÍ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum,minn;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		s[i]=(i-1)*(a[i]-a[i-1])+s[i-1];
		d[i]=d[i-1]+s[i];
	}
	int l=1,r=n;
	int mid=(l+r)/2;
	while(!(mid==l||mid==r)){
		minn=INT_MAX;
		for(int i=1;i<=n-mid;i++){
			sum=s[i+mid]+d[i-1]-(i-1)*a[i+mid];
			minn=min(minn,sum);
		}
		if(minn>m){
			r=mid;
		}else{
			l=mid;
		}
		mid=(r+l)/2;
	}
	cout<<mid+1;
	return 0;
} 
