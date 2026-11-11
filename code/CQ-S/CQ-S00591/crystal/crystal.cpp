#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],c;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		int s=0;
		for(int i=1;i<=n;++i){
			s+=(a[i]-a[i-1])*(i-1);
			if(s>m||s<0){c==i-1;break;}
		}
	}
	else{
		for(int i=1;i<=n;++i){
			int s=0,x=1;
			for(int j=i-1;j>=1&&s<=m;j--){s+=(a[i]-a[j]);x++;}
			c=max(c,x);
		}
	}
	cout<<c;
	return 0;
}
