#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],l,r,mid;
bool check(long long x){
	bool f=0;
	for(int i=1;i<=n-x+1;i++){
		if((a[i+x-1]*(x-1)-(s[i+x-2]-s[i-1]))<=m){
			f=1;
			break;
		}
	}
	return f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	
	l=1;r=n;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
}
