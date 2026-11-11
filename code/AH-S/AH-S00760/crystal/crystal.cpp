#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+500;
int n;
ll m;
ll a[N];
int check(int x){
	int l=x-1,sum=1;
	int mm=m;
	while(l>=1&&mm>=a[x]-a[l])mm-=a[x]-a[l],l--,sum++;
	return sum;
}
ll d;
int check2(int x){
	int l=1,r=x,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if((x-mid+1)*(x-mid)*d/2<=m)r=mid-1,ans=x-mid+1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int flag=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
	}
	if(flag){
		int ans=0;
		d=a[2]-a[1];
		for(int i=1;i<=n;i++)ans=max(ans,check2(i));
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,check(i));
	cout<<ans;
	return 0;
}

