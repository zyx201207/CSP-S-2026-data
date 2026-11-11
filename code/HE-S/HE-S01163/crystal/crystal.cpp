#include<bits/stdc++.h>
using namespace std;
long long a[500010]={};
long long b[500010]={};
long long n,m;
bool check(int x,int i){
	long long num=1LL*a[i]*(i-x+1)-1LL*(b[i]-b[x-1]);
//	cout<<num<<endl;
	if(num<=m){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int maxx=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
//		cout<<b[i]<<' ';
		int l=1,r=i;
		int ans=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(i-ans+1>maxx){
			maxx=i-ans+1;
		}
	}
	cout<<maxx;
	return 0;
}
