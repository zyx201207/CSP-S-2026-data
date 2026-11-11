#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],s[N],ans;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	ans=n;
	while(ans*a[ans]-s[ans]>m){ans--;}
	cout<<ans<<endl;
	return 0;
}
