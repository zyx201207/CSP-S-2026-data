#include <bits/stdc++.h> 
using namespace std;

long long n,m,a[1000000];

bool check(int cnt){
	int sum=1,k=m;
	for(int i=2;i<=n;i++){
		if(sum>=cnt) return 1;
		if((a[i]-a[i-1])*(i-1)>k) break;
		else{
			k=k-(a[i]-a[i-1])*(i-1);
			sum++;
		}
	}
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
