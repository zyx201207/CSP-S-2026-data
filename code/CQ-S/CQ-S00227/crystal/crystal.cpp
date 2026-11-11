#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define pb push_back
/*

*/ 
int n;
int m;

int a[500009];

bool check(int x){
	int sum=0;
	for (int i=1;i<x;i++){
		sum=sum+(a[x]-a[i]); 
	}
	bool f=(sum<=m);
//	cout<<sum<<' ';
	for (int i=x+1;i<=n;i++){
		sum=sum+(x-1)*(a[i]-a[i-1])-(a[i-1]-a[i-x]);
		if (sum<=m){
			f=true;
		}
	}
	return f;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
//	cout<<check(3);
	
	int l=1,r=n,ans=0;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}







