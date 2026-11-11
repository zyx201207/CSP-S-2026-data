#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int MAXN=5e5+10;
long long pos[MAXN];
long long a[MAXN];
long long ans=-MAXN;
long long n,m;
int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++){
		pos[i]=pos[i-1]+a[i];
	}
	long long l=1;
	long long r=1;
	while(l<=n&&r<=n){
		long long temp=a[r]*(r-l+1)-(pos[r]-pos[l-1]);
		if(temp<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}