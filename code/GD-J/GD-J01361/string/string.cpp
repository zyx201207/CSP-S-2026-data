#include<bits/stdc++.h>
#define int long long
std::string s;
int a[200005];
char c[200005];
int len,n;
int ps[200005];
char cal(int x){
	int pos=std::lower_bound(ps+1,ps+n+1,x)-ps;
	return c[pos];
}
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::freopen("string.in","r",stdin);
	std::freopen("string.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i]>>c[i];
		len+=a[i];
		ps[i]=len;
	}
	int ans=0;
	for(int i=1;i<=len;i++){
		int j=len-i+1;
		if(i>j)break;
		if(cal(i)!=cal(j))++ans;
		
	}	
	std::cout<<ans<<'\n';
	return 0;
}
