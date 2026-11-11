#include<bits/stdc++.h>
using namespace std;
long long a[600001],n,m;
void point45(int n,int m){
	long long minn=100010,maxn=-100010,ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a,a+n);
	for(int i=minn;i<=maxn;i++){
		int j;
		int least;
		long long m1=m;
		for(j=n;j>=0;j--){
			if(a[j]<=i){
				least=j;
				break;
			}
		}
		long long k=least,cnt=0;
		while(k>=0&&m1>0){
			cnt++;
			k--;
			m1-=abs(i-a[k]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
void point55(int n,int m){
	long long ans=0,cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	long long cha=a[1]-a[0];
	sort(a,a+n);
	long long bei=0;
	long long mid=ans/n;
	while(m>0){
		if(m-cha*bei>0){
			bei++;
			m-=mid-(cha*bei);
			cnt++;
		}
	}
	cout<<cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000&&m<=1e9){
		point45(n,m);
	}else{
		point55(n,m);
	}
	return 0;
}
