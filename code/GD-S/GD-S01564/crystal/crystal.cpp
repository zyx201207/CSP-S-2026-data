#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
int getsum(int l,int r){
	int ans=0;
	for(int i=l;i<r;i++)ans+=a[r]-a[i];
	return ans;
}
void sub1(){
	vector<int>d(n+1,0),pre(n+1,0);
	d[1]=a[2]-a[1];
	pre[1]=d[1];
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+d[1];
		pre[i]=pre[i-1]+d[i];
	}
	int l=1,r=2;
	while(r<=n){
		int dis=l-1;
		int rc=r-dis-1;
		while(pre[rc]>m)l++,dis=l-1,rc=r-dis-1;
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	exit(0);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	int dif;
	bool flag=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i==2)dif=a[i]-a[i-1];
		else if(i>=2&&a[i]-a[i-1]!=dif)flag=0;
	}
	if(flag)sub1(); 
	sort(a+1,a+n+1);
	int l=1,r=2;
	while(r<=n){
		while(getsum(l,r)>m)l++;
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans; 
	return 0;
}
/*

*/
