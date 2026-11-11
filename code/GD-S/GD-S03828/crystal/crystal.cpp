#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
int a[500005],s[500005],dq;
int n,m;
bool check(int x){
//	cout<<"!!!!"<<dq<<" "<<x<<endl;
	int sum=a[dq]*x;
//	cout<<sum<<" ";
	sum-=(s[dq]-s[dq-x]);
//	cout<<sum<<endl; 
	if(m>=sum)return 1;
	return 0; 
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		dq=i;
		int l=0,r=i,res=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				res=mid;
		//		cout<<mid<<"OK"<<endl;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,res);
		//cout<<i<<" "<<res<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
