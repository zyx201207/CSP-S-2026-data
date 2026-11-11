#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar()
#define pc putchar
inline bool isnum(char&num){return num>='0'&&num<='9';}
inline void read(int&x)
{
	x=0;int f=1;char ch=gc;
	while(!isnum(ch)){if(ch=='-')f=-1;ch=gc;}
	while(isnum(ch)){x=x*10+ch-'0';ch=gc;}
	x*=f;
}
inline void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+'0');
}
const int Max=5e5;
int n,m,a[Max+32],sum[Max+32],ans=1;
inline bool cmp(const int&a,const int&b){return a<b;}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		sum[i]=a[i]+sum[i-1];
	for(int j=1,i=2;i<=n;i++)
	{
		while(a[i]*(i-j)-sum[i-1]+sum[j-1]>m)j++;
		ans=max(i-j+1,ans);
	}
	write(ans);
	return 0;
}