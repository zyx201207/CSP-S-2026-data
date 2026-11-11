#include<bits/stdc++.h>
#define int long long 
using namespace std;
long long n;
long long m;
int ans;
long long a[1000100],s[1000100]; 
bool ck(long long l,long long r,int id){
	long long cnt = (r-l+1)*(a[id]) - (s[r]-s[l-1]);
	if(cnt <= m){
		return 1;
	}
	else return 0;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		s[i] = a[i]+s[i-1];
	} 
	for(int i = 1;i <= n;i++){//以ai为目标 
		//cout<<a[i]<<endl;
		int l = 1,r = i-1;
		while(l <= r){
			int mid = (l+r)/2;
			//从mid到i-1 的代价小于等于 m
			if(ck(mid,i-1,i)){
				r = mid-1;
				ans = max(ans,i-mid+1);
				//记录合法答案 
				
			} 
			else{
				l = mid+1;
			}
		}
	}
	cout<<ans;
	return 0; 
} 
