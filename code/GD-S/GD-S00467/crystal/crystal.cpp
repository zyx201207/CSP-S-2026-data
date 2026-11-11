#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
long long m;
int ans,fen;
long long a[500005];
long long s[500005];
int find(int t){
	int l,r;
	l=1,r=t;
	while(l<=r){
		int mid=l+r>>1;
		if((t-mid+1)*a[t]+s[mid-1]-s[t]>m)l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int mid=i;
		mid=find(i);
		ans=max(ans,i-mid+1);
	}
	cout<<ans;
	return 0;
} 
