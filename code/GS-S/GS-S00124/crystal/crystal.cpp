/*
	crystal
	
	
*/ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int n;
ll m;
ll a[N];
ll tmp_sum[N],sum[N];
ll cha[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	//计算前缀和
	for(int i=2;i<=n;i++){
		cha[i-1]=a[i]-a[i-1];
//		cout<<cha[i-1]<<" ";
	} 
//	cout<<"\n";
	for(int i=n;i>=1;i--){
		tmp_sum[i]=tmp_sum[i+1]+cha[i];
		sum[i]=sum[i+1]+tmp_sum[i];
//		cout<<sum[i]<<" ";
	}
//	cout<<"\n";
	
	//寻找答案
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1;
		int tmp=0;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(sum[mid]-sum[i]-1ll*(i-mid)*tmp_sum[i]<=m){
				tmp=i-mid+1;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		} 
		ans=max(ans,tmp);
	} 
	
	//输出
	cout<<ans<<"\n"; 
	return 0;
}
