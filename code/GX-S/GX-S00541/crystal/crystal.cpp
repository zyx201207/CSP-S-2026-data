#include<bits/stdc++.h>

using namespace std;

const int N=5e5+10;
int n;
long long m,ans;
long long a[N]; 
bool check(long long mid){
	long long cnt=0;
	for(int i=1;i<mid;i++){
		cnt+=a[mid]-a[i];
	}
	if(cnt<=m){
		return true;
	}
	else{
		return false;
	}
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
	long long l=0,mid,r=n+1;
	while(l<r){
		mid=(r-l)/2+l;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}
