#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
int read(){
	int x=0;bool neg=false;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=true;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return neg?-x:x;
}
signed main(){
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=l+r>>1;
			int x=(i-mid)*a[i]-(s[i-1]-s[mid-1]);
			if(x>m) l=mid+1;
			else r=mid;
		}
		//cerr<<l<<' ';
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
