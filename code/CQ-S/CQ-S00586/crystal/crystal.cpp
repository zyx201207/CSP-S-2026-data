#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long l=10^12,r=-10^12,m,cnt=0;
	cin>>n>>m;
	vector<long long> arr(n);
	for(int i=0;i<n;++i) cin>>arr[i],l=min(l,arr[i]),r=max(r,arr[i]);
	sort(arr.begin(),arr.end());
	auto middle=[&](long long mid){
		long long c=0,cha=0;
		for(int i=0;i<n;++i){
			if(arr[i]<=mid) ++c,cha+=mid-arr[i];
			else break;
		}
		if(cha<=m){
			cnt=max(cnt,c);
			return true;
		}else return false;
	};
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(middle(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<cnt<<"\n";
	return 0;}