#include<bits/stdc++.h>
using namespace std;
void in(int &x){
	int f=1;x=0;char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}
	x*=f;
}
const int N=505;
const int M=5e5+5;
const long long inf=1e18;
int id,n,m,d,q,w[M];
long long dis[N][N];
#define pr pair<int,int>
#define mp make_pair
vector<pr>pos[M];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=(i==j?0:inf);
		}
	}
	for(int i=1;i<=m;i++){
		for(auto X:pos[i]){
			long long a=X.first,b=X.second;
			for(auto Y:pos[i]){
				long long c=Y.first,d=Y.second;
				dis[a][c]=dis[c][a]=min(dis[a][c],b+d);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i==j||i==k||j==k)continue;
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	in(id);in(n);in(m);in(d);in(q);
	for(int i=1;i<=m;i++)in(w[i]);
	for(int i=1;i<=n;i++){
		int al;in(al);
		for(int j=1;j<=al;j++){
			int x,y;in(x);in(y);
			pos[x].push_back(mp(i,y));
		}
	}
	floyd();
	while(q--){
		int x,y;long long ans=1e18;
		in(x);in(y);
		for(auto X:pos[x]){
			long long a=X.first,b=X.second;
			for(auto Y:pos[y]){
				long long c=Y.first,d=Y.second;
				ans=min(ans,w[x]*1ll+w[y]*1ll+b*1ll+d*1ll+dis[a][c]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

/*
把路线设为点,floyd
询问暴力枚举进线出线 
复杂度O(n^3+q*d^2+m*d^2) 
*/
/*
/*

那也请不要忘记 落泪的眼睛 曾动容的心情 

浮游之人 也挣扎不已执着存在下去
追逐着 梦想着 继续


 
乞求明天不会到来就好了之类的空想
将这一切湮灭的便是你的愿望
伫立于从不存在奇迹的世界中央
待钟声敲响 


夜空从不会
因谁离开而改变
就算千万次晴朗后又是雨天
幸福悬挂在
每个平凡的夜晚
感谢它曾让生命灿烂
 
*/
