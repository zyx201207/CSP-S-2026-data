#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],b[N];
long long n,m; 
bool check(long long mid){
	for(int i=mid;i<=n;i++){
		if(mid*a[i]-b[i]+b[i-mid]<=m)return true;
	}
	return false;
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
		b[i]=b[i-1]+a[i];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	} 
	cout<<l;
    return 0;
}

