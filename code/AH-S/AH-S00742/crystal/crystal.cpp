#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N];
long long s[N];
long long n,m;
bool check(long long x,long long val,long long idx){
	return (s[idx]-s[idx-x])+m>=x*val;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int maxn=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid,a[i],i)){
				l=mid;
				maxn=max(maxn,mid);
			}else{
				r=mid-1;
			} 
		}
	}
	cout<<maxn;
	return 0;
}

