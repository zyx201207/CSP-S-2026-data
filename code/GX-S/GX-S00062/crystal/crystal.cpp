//CCF I love you.Could you please give me more scores?
//中国计算机协会我爱您。您可否乐意给予我更多的得分呢？
using i128=__int128;
using u128=unsigned __int128;
const i128 INF=(static_cast<__int128>(1)<<126)+((static_cast<__int128>(1)<<126)-1);
const i128 NEG=-INF-1;
#include<cstdio>
#define MIAO(_x,_y) freopen(_x,"r",stdin);freopen(_y,"w",stdout);
template<typename T=__int128>
inline T read(){T t{};bool f=0;char c=getchar();
	while(c!=EOF&&(c<'0'||c>'9'))f=c=='-',c=getchar();
	while(c!=EOF&&!(c<'0'||c>'9'))t*=10,t+=c-'0',c=getchar();
	if(c!=EOF)ungetc(c,stdin);
	return f?-t:t;
}
template<typename T>
inline void write(const T&t){
	if(t<0)return putchar('-'),write(-t);
	if(t>9)write(t/10);
	putchar(t%10+'0');
}
#include<vector>
#include<algorithm>
i128 n,m,cnt,ans=1,i,j;
std::vector<i128>a;
inline bool check(){}
int main(){
	MIAO("crystal.in","crystal.out");
	n=read();m=read();
	a.resize(n);
	for(auto&&i:a)i=read();
	std::sort(a.begin(),a.end());
	for(i=0,j=1;j<n;j++){
		cnt+=(j-i)*(a[j]-a[j-1]);
		while(cnt>m){
			ans=ans>(j-i)?ans:j-i;
			cnt-=(a[j]-a[i]);
			i++;
		}
	}
	ans=ans>(j-i+1)?ans:j-i+1;
	write(ans);putchar('\n');
	return 0;
}
/*
贪心……贪心？	-10/31 14:40
双指针？	-10/31 15:20
对了，就是双指针！俺寻思俺可以拿下100pts。	-10/31 15:30
*/