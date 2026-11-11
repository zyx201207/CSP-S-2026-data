#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	long long a[n+1]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	long long l=1,r=n,an=0;
	while(l<=r){
		long long mid=(l+r)/2;
		long long su=0;
		for(int i=1;i<mid;i++){
			su+=(a[mid]-a[i]);
		}
		if(su==m){
			an=max(an,mid);
			l=mid+1;
		}else if(su>m){
			r=mid-1;
		}else if(su<m){
			an=max(an,mid);
			l=mid+1;
		}
	}
	cout<<an;
	return 0;
}
