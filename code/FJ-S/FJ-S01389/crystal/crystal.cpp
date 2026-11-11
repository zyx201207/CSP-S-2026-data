#include<bits/stdc++.h>//kskbl zdjd  wk zds dddl 切得比j t1快哈哈哈 
#define int long long
using namespace std;
int n,a[500005],m,c[500005],ans;
int l=1,x;//left 现所需操作 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int r=2;r<=n;r++){
		x+=(a[r]-a[r-1])*(r-l);
		while(x>m){
			x-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1); 
	}
	cout<<ans;
	return 0;
}
