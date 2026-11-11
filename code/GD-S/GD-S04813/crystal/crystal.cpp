#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#ifdef DEBUG
void dbg(){cerr<<endl;}
template<typename A,typename...B>void dbg(A a,B...b){cerr<<a<<" ",dbg(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", dbg(x)
#else
#define debug(...) (void)1
#endif


int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	i64 m;
	
	cin>>n>>m;
	vector<i64>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+n+1);
	vector<i64>s(n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=0,r=n,res=0;
	i64 start;
	auto chk=[&](int x)->bool{
		for(int i=x;i<=n;i++){
			i64 need=a[i]*x;
			i64 get=s[i]-s[i-x];
			if(need-get<=m){
				start=i;
				return true;
			}
		}
		return false;
	};
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1,res=mid;
		else r=mid-1; 
	}
	cout<<res<<'\n';
	
	return 0;
} 
