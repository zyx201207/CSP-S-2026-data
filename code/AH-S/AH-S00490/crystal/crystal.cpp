#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked

inline int read(){
	int x=0,v=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')v=-1;
		ch=gc();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+(ch-'0');
		ch=gc();
	}
	return x*v;
}

const int N=5*1e5+10;
int n,m,a[N],c[N];
int now=1,need,l=1,ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	
	for(int i=2;i<=n;i++){
		need+=c[i]*(i-l);
		now++;
		while(need>m){
			need-=(a[i]-a[l]);
			now--,l++;
		}
		ans=max(now,ans);
	}
	
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
