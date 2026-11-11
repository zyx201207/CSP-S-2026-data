#include<bits/stdc++.h>
using namespace std;
#define int long long
#define v vector
const int Max=1e17;
inline int read(){
	char c=getchar();
	int x=0;bool b=1;
	while(c<'0'||c>'9')
	{if(c=='-')b=0;
	c=getchar();}
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+(c^48),
	c=getchar();
	return b?x:-x;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct P{int l,r;};
int n,m,q,i,j,l,r,_;
v<int>t;
v<v<int> >s;
v<v<P> >k;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),read(),q=read();
	t=v<int>(m+1);k=v<v<P> >(m+1);
	s=v<v<int> >(n,v<int>(n,Max));
	for(i=1;i<=m;i++)t[i]=read();
	for(i=0;i<n;i++){
		j=read();while(j--)
		l=read(),r=read(),
		k[l].push_back({i,r});
	}
	for(i=0;i<n;i++)
	s[i][i]=0;
	for(i=1;i<=m;i++){
		for(l=0;l<k[i].size();l++)
		for(r=0;r<k[i].size();r++)
		s[k[i][l].l][k[i][r].l]=min(
		s[k[i][l].l][k[i][r].l],
		k[i][l].r+k[i][r].r);
	}
	for(i=0;i<n;i++)
	for(l=0;l<n;l++)
	for(r=0;r<n;r++)
	s[l][r]=min(s[l][r],
	s[l][i]+s[i][r]);
	while(q--){
		l=read(),r=read();_=Max;
		for(i=0;i<k[l].size();i++)
		for(j=0;j<k[r].size();j++)
		_=min(_,k[l][i].r+s[k[l][i].l][k[r][j].l]+k[r][j].r);
		write(_+t[l]+t[r]);putchar('\n');
	}
	return 0;
}
