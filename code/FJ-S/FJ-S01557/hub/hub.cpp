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
int c,t;
void getpf(int num)
{
	for(int i=1;i<=num;i++){
		write(0);//神入随机数
		putchar('\n');
	}
}
signed main()
{
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	read(c);read(t);
	getpf(t);
	return 0;
}