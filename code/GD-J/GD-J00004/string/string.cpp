#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
const int N=2e5+10;
int n,a[N];
char c[N];
int l,r,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),cin>>c[i];
	l=1,r=n;
	while(l<r){
		if(c[l]!=c[r])ans+=min(a[l],a[r]);
		if(a[l]<a[r])a[r]-=a[l],l++;
		else if(a[l]==a[r])l++,r--;
		else a[l]-=a[r],r--;
	}
	write(ans);
	return 0;
}
