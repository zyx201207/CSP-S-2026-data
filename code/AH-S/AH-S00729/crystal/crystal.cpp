#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
bool check(int mid){
	long long cur=0;
	for(int i=1;i<=mid;i++){
		cur+=a[mid]-a[i];
	}
	if(cur<=m){
		return 1;
	}
	for(int i=2,j=mid+1;j<=n;i++,j++){
		cur+=(a[j]-a[j-1])*(mid-1);
		cur-=a[j-1]-a[i-1];
		if(cur<=m){
			return 1;
		}
	}
	return 0;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
//复杂度分析：排序O(nlogn),二分*check O(nlogn)，瓶颈在排序，可以通过所有数据 
