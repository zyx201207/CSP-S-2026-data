#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
bool check(int x){
	long long ans=0;
	for(int i=1;i<=x;i++){
		ans+=(a[x]-a[i]);
	}
	if(ans>m){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long h=1;
	long long t=n;
	while(h<t){
		long long mid=(h+t+1)/2;
		if(check(mid)){
			h=mid;
		}else{
			t=mid-1;
		}
	}
	cout<<t;
	return 0;
} 
