#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans=0;
	long long sum=INT_MIN;
	for(int i=0;i<n;i++){
		if(n-i<=ans) break;
		long long cnt=m;
		for(int j=i+1;j<n;j++){
			if(sum==a[i])break;
			if(a[j]!=a[i]){
				if(a[j]>sum)sum=a[j];
				if(cnt>=a[i]-a[j]){
					cnt-=a[i]-a[j];
					if(j==n-1) ans=max(ans,j-i+1);
				}else{
					ans=max(ans,j-i);
					break;
				}
			}
		}
		sum=a[i];
	}
	cout<<ans;
	return 0;
}
