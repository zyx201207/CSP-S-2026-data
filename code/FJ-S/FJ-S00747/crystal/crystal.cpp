#include<bits/stdc++.h>
#define int long long
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
template<typename T>void read(T &x){
	x=0;T f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){if(c=='-')f=-1;c=getchar();}
	while((c>='0'&&c<='9')){x=x*10+(c^48);c=getchar();}
	x*=f;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,a[555555],s[555555];
bool check(int x){
	for(int i=x;i<=n;i++){
		int fr=i-x+1;
		int ss=x*a[i]-(s[i]-s[fr-1]);
		//a[fr]+a[fr+1]+...+a[i]
		//cout<<fr<<" "<<i<<" "<<ss<<"\n";
		if(ss<=m)return true;
	}
	return false;
}
signed main(){
	file("crystal")
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		//cout<<mid<<'\n';
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	write(ans);puts("");
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 7
4 4 -3 5 6 
*/
