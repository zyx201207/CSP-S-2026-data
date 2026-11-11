#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::string;

typedef long long ll;

const int N=5e5+5;

int n;
ll m;
ll a[N],s[N];

int max1=1;

int uppr_bnd(int st){
	int l=st,r=n;
	int ans=n+1;
	
	while(l<=r){
		int mid=(l+r)>>1;
		if(ll((mid-st)*a[mid]-(s[mid-1]-s[st-1]))>m){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	
	return ans-1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	std::sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int st=1;
	while(st<=n){
		max1=std::max(max1,uppr_bnd(st)-st+1);
		st++;
	}
	cout<<max1;
	
	return 0;
} 
