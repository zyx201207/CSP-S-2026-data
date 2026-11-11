#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[500005];
int l=1e18,r=-1e18;
int num[500005];
int cf[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	sort(arr+1,arr+1+n);
	for(int i=2;i<=n;i++){
		cf[i]=arr[i]-arr[i-1];
	}
	for(int i=2;i<=n;i++){
		num[i]=num[i-1]+cf[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		int minn=1e9;
		int sum=0;
		for(int i=2;i<=mid;i++){
			sum+=num[mid]-num[i-1];
//			cout<<sum<<endl;
		}
		minn=min(minn,sum);
//		cout<<mid<<endl;
//		cout<<sum<<" ";
		for(int j=mid+1;j<=n;j++){
			int js=num[j-1]-num[j-mid];
			int ad=(num[j]-num[j-1])*(mid-1);
//			cout<<js<<" "<<ad<<endl;
			sum-=js;
			sum+=ad;
			minn=min(minn,sum);
//			cout<<sum<<" ";
		}
//		cout<<endl;
		if(minn<=m){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
