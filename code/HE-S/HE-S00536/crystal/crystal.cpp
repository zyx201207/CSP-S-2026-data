#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+10;
int n,ans;
long long a[N],m,s[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!=EOF&&(ch<'0'||ch>'9')) { if(ch=='-') f=-1; ch=getchar(); }
	while(ch!=EOF&&(ch>='0'&&ch<='9')) { x=x*10+ch-48; ch=getchar(); }
	return x*f;
}
inline long long read_ll(){
	long long x=0,f=1;char ch=getchar();
	while(ch!=EOF&&(ch<'0'||ch>'9')) { if(ch=='-') f=-1; ch=getchar(); }
	while(ch!=EOF&&(ch>='0'&&ch<='9')) { x=x*10+ch-48; ch=getchar(); }
	return x*f;
}
bool check(int i,int l){
	if((i-l)*a[i]-m<=s[i-1]-s[l-1]) return true;
	return false;
}
int solve(int now){
	int l=1,r=now;
	while(l!=r){
		int mid=(l+r)>>1;
		if(check(now,mid)) r=mid;
		else l=mid+1;
	}
	return now-l+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read_ll();
	for(int i=1;i<=n;i++) a[i]=read_ll();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) ans=max(ans,solve(i));		
	cout<<ans;
	return 0; 
}
