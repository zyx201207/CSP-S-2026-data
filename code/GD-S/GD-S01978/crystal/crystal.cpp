#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,m,a[N],s[N];

int check(int l,int r){
	return m>=((r-l)*a[r]-(s[r-1]-s[l-1]));
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,nw=1;
		while(l<=r){
			int md=(l+r)>>1;
			if(check(md,i)){
				nw=i-md+1;
				r=md-1;
			}else{
				l=md+1;
			}
		}
		ans=max(ans,nw); 
	}
	cout<<ans;
	return 0;
} 
/* 
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
