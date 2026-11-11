#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,l,r;
int ans;
int a[1000005];
int s[1000005];
bool cmp(int x,int y){
	return x<y;
}
bool check(int x){
//	bool res=0;
//	cout<<"("<<x<<")"<<"\n";
	for(int i=x;i<=n;i++){
		int now=a[i];
		int sum=s[i]-s[i-x];
//		cout<<i<<":"<<now<<" "<<sum<<"\n";
		if(m>=now*x-sum)return 1;
	}
	return 0;
}
void f(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
//			cout<<"ok\n";
		}else{
			r=mid-1;
//			cout<<"no\n";
		}
	}
	cout<<ans<<"\n";
}
signed main(){
//	freopen("crystal5.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--)
	f();
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7

*/
