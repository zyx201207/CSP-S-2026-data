#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],m;
bool check(int x){
	long long cnt=0;
	for(int i=1;i<=x;i++){
		cnt+=a[x]-a[i];
		if(cnt>m)return 0;
	}
	
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<m<<' ';
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	
	long long l=1,r=n;
	while(l<r){
		//cout<<l<<' '<<r<<' ';
		int mid=(l+r)/2+1;
		//cout<<check(mid)<<'\n';
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<'\n';
	return 0;
}
