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
#include<queue>
#include<array>
i128 c,t,n,d,ans;
std::vector<i128>a;
std::queue<std::pair<i128,i128>>q;
inline bool bfs(const i128&s,const i128&t){//S&T都是下标。
	q.push({s,0});std::vector<i128>dis;
	while(!q.empty()){
		auto x=q.front().first;auto dep=q.front().second;q.pop();
		if(x==t&&dis.size()<3){
			dis.push_back(dep);
			continue;
		}
		for(i128 i=x+1;i<=t&&a[i]-a[x]<=d;i++)q.push({i,dep+1});
	}
	return (dis.size()==2&&dis[0]==dis[1])||(dis.size()==3&&(dis[0]==dis[1]&&dis[1]!=dis[2]));
}
int main(){
	MIAO("migrate.in","migrate.out");
	c=read();t=read();
	while(t--){
		n=read();d=read();
		a.assign(n,{});ans=0;
		for(auto&&i:a)i=read();
		for(i128 i=0;i<n;i++)
			for(i128 j=i+1;j<n;j++)
				ans+=bfs(i,j);
		write(ans);putchar('\n');
	}
	return 0;
}
/*
dp?	-10/31 16:39
想欲于阮 出外的人 飞向一个繁华世界/一站一站过过停停 男儿的天外天/想欲于阮 故乡的人 看着阮的思念心情/一步一步摇摇摆摆 故乡的田边（阮的老厝边）	-10/31 16:48
bfs+计数？	-10/31 16:50
头晕。感觉发烧了。	-10/31 16:53
mokongbro will never die!	-10/31 16:56
洛谷用户DY0601，膜拜大佬%%%	-10/31 16:58
预估分数8pts	-10/31 17:19
线段树？	-10/31 17:21
*/