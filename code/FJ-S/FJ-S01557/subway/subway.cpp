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
int c,n,m,d,q;
void getpf(int num)
{
	for(int i=1;i<=num;i++){
		write(((i+num/i+(num^i))^32)*(0x3263263263263232)+666*(i%2==1?1:-1));//神入随机数
		putchar('\n');
	}
}
signed main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	read(c);read(n);read(m);read(d);read(q);
	getpf(q);
	return 0;
}