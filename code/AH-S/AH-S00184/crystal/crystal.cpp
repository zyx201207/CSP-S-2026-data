#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int read(){
	char c;
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}


int n,m,a[N],ans;
bool check(int x){
	int tmp=a[x],cnt=0;
	for(int i=1;i<x;i++){
		cnt+=(tmp-a[i]);
		if(cnt>m) return false;
	}
	if(cnt<=m) return true;
	else return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
