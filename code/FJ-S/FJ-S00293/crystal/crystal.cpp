#include<bits/stdc++.h>
using namespace std;
#define int long long
#define v vector
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
int n,m,i,t,ans;
v<int>s;
queue<int>k;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();s=v<int>(n);
	for(i=0;i<n;i++)s[i]=read();
	sort(s.begin(),s.end());
	ans=1;k.push(s[0]);t=0;
	for(i=1;i<n;i++){
		t+=(s[i]-s[i-1])*k.size();
		k.push(s[i]);while(t>m)
		{t-=s[i]-k.front();k.pop();}
		ans=max(ans,(int)k.size());
	}
	write(ans);
	return 0;
}
