#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	long long m;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int num=0,sum=1,l=0,r=0;
	for(int i=1;i<n;i++){
		if(num+abs(a[0]-a[i])<=m){
			sum++;
			r++;
			num+=abs(a[0]-a[i]);
		}
	}
	int ans=sum;
	for(int i=2;i<n;i++){
		num=num-abs(a[l]-a[l+1])*(r-l)+abs(a[r]-a[r+1])*(r-l);
		l++,r++;
		
		while(num+abs(a[l]-a[r+1])<=m){
			num+=abs(a[l]-a[r+1]);
			sum++,r++;
		}
		if(r+1==n){
			ans=max(ans,sum);
			cout<<ans<<"\n";
			return 0;
		}
		
		while(num>m){
			num-=abs(a[l]-a[r]);
			sum--,r--;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}
