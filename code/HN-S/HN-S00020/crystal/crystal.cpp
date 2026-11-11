#include<bits/stdc++.h>
#define qwe(i,l,r) for(int i=(l);(i)<=(r);++i)
#define ewq(i,l,r) for(int i=(l);(i)>=(r);--i)
#define qwex(e,x) for(int e=(x);e;e=ne[e])
#define ll long long
#define int ll
#define pii pair<int,int>
#define fir first
#define sec second
#define low(x) (x)&(-(x))
#define whlie while
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=5e5+5;
int n,m,a[N],s[N];
bool check(int x){
	qwe(i,x,n){
//		if(x==3&&i==3)printf("asd %lld\n",a[i]*x-(s[i]-s[i-x]));
		if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	qwe(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	qwe(i,1,n)s[i]=s[i-1]+a[i];
	int l=1,r=n,mid,op=-1;
	while(l<=r){
		mid=l+r>>1;
//		cout<<mid</<'\n';
		if(check(mid)){
			op=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<op;
}
