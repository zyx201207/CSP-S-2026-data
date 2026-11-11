#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N],s[N],s2[N],s3[N],s4[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		s[i]=a[i+1]-a[i];//差分 
	}
	s2[1]=s[1];
	for(int i=1;i<n;i++){
		s2[i+1]=s2[i]+s[i+1];//差分前缀和 
	}
	s3[1]=s2[1];
	for(int i=1;i<n;i++){
		s3[i+1]=s3[i]+s2[i+1];//s2前缀和 
	}
	s4[1]=0;
	for(int i=2;i<=n;i++){
		s4[i]=s2[i-1]*i-s3[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s4[i]<=m){
			ans=max(ans,i);
			continue;
		}
		int mod=s2[i-1],cnt=i;
		int now=s4[i]-m;
		int k=0;
		while(now>0){
			k+=now/mod+1;
			now=now-(now/mod+1)*mod+s3[k]-s3[k-now/mod-1];
			cnt=i-k;
//			int num3=num1+now/mod;
//			if(now<mod)now=0,num3++;
//			now=now%mod+s3[num3]-s3[num1];
//			cnt-=num3-num1;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<s[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<s2[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<s3[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<s4[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=n;i>=2;i--){
//		if(s4[i]<=m){
//			cout<<i;
//			return 0;
//		}
//	}
	return 0;
}
