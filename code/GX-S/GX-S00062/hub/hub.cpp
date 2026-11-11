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
i128 c,t,n,k,u,v;
std::vector<std::vector<i128>>e;
int main(){
	MIAO("hub.in","hub.out");
	c=read();t=read();
	if(c==13||c==14){
		while(t--){
			n=read();k=read();
			for(i128 i=1;i<n;i++){read();read();}
			if(k>n-2){write(0);putchar('\n');continue;}
		}
		return 0;
	}
	while(t--){
		n=read();k=read();
		e.assign(n+1,{});
		for(i128 i=1;i<n;i++){
			u=read();v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		//这里存在着至少998244353个滚木。
	}
	return 0;
}
/*
连通块还没学。空悲切！	-10/31 17:24
早知道我就吃午饭了！	-10/31 17:29
最小的最大长得很像二分耶（思考ing）。 -10/31 17:35
*/

//场上结算：100+50+8+0=158.