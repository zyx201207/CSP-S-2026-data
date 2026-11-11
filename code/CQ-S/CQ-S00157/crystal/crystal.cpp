#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int check(int x){
	for(int i=x;i<=n;i++){
		if(i==x){
			if(b[x]<=m){return b[x];}
			continue; 
		}
		int opt=b[i-x]+(a[i]-a[i-x])*(i-x);
		int checkk=b[i]-opt;
		if(checkk<=m){return checkk;}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]) ;
	}
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;ans=mid;
		}
		else r=mid-1;
	} 
	cout<<ans;
	return 0;
}
/*
10 20
1 99 100 20000 20000 20005 20006 20005 20000 1
*/
