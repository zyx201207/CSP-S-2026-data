#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
int n,m,a[500010],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int j=1,s=0;
	for(int i=2;i<=n;i++){
		s+=(i-j)*(a[i]-a[i-1]);
		while(s>m){
			s-=a[i]-a[j];
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
int read(){
	int s=0,sg=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')sg=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*sg;
}