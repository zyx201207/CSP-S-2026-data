#include<bits/stdc++.h> 
using namespace std;
const int N=5*1e5+10;
long long n,m,ans;
long long a[N];
long long s[N];
bool check(int x){
	long long minm=0x3fffffffffffffff;
	
	
	for (int i=x;i<=n;i++){
		long long t=s[i]-s[i-x];
		minm=min(minm,a[i]*x-t);
	}
	return minm<=m;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){		
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=5*1e5;
	while (l<r){
		int mid=(l+r+1)/2;
		if (check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
