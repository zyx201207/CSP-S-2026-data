//华东师范大学附属贵阳学校 GZ-S00367 林越航
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[200005],ans=1;
bool check(long long x){
	long long sum=0;
	for(int i=1;i<x;i++){
		sum+=a[x]-a[i];
		if(sum>m)return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<r){
		long long mid=l+(r-l+1)/2,cnt=0;
		if(check(mid)){
			for(int i=mid+1;i<=n;i++){
				if(a[mid]==a[i])cnt++;
				else break;
			}
			ans=mid+cnt;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
