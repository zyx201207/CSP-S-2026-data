#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m;
int a[N];
int mia=1e12+5,mxa=-(1e12+5);
bool check(int k){
	int res=0;
	for(int i=1;i<=n;i++)
		if(k>a[i])res+=(k-a[i]);	
	//cout<<res<<endl;
	if(res<=m)return 1;	
	else return 0;				
}
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	/*ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);	*/
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mxa=max(mxa,a[i]);
		mia=min(mia,a[i]);
	}
	
	int l=mia,r=mxa;
	
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	sort(a+1,a+n+1);
	int ans=0,t=0;
	//l=2; 
	//cout<<l<<endl;
	
	//ans=upper_bound(a+1,a+n+1,l)-a-1;
	for(int i=1;i<=n;i++){
		if(a[i]<=l)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
/*
5 5
1 2 4 8 9
4

5 8
-3 -1 2 2 7

4 9
-3 -1 3 3

4 9
-3 -1 2 2

*/
