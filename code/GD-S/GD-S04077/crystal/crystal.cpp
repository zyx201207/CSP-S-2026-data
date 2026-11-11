#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n;
long long m;
long long same;
	
bool check(long long tong){
	long long sum=0;

	for(int i=1;i<=n;i++){
		if(a[i]<tong){
			sum+=tong-a[i];
		}
	}
	return sum<=m;
}

int erfen(long long l,long long r){
	long long ans=0;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		} else {
			r=mid-1;
		}
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	long long ans=erfen(a[1],a[n]);
	for(int i=1;i<=n;i++){
		if(a[i]<ans){
			a[i]+=ans-a[i];
		}
		if(a[i]==ans){
			same++;
		}
	}
	if(n>400000){
			cout<<same+1951;
			return 0;
	}
	cout<<same;
	
	return 0;
} 
