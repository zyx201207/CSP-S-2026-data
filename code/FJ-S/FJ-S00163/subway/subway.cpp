/*
1.是否开long long，空间够不够？
2.数组大小开到上限+10了吗？
3.边数组是否够？
4.多测清空？
5.多测读完数据再特判？
6.跑过极限数据？
7.暴力分，特殊性质打满了吗？
8.freopen不要注释！！！
*/
#include<bits/stdc++.h>
#define ump unordered_map
using namespace std;
const int N=5e5+10;
typedef long long ll;
int c,n,m,d,q,w[N],k[510],xr,yr;
ll dis[510][510],ans;
ump<int,ump<int,int> >mp;
//线路编号、站点编号->线路中站点位次
vector<int>a[510],t[510],z[N];//每个地铁站的经过地铁线路编号
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+48);
	else write(x/10),putchar(x%10+48);
	return;
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		k[i]=read();
		a[i].push_back(0),t[i].push_back(0);
		for(int j=1,aa,tt;j<=k[i];j++){
			aa=read(),tt=read();
			a[i].push_back(aa);
			t[i].push_back(tt);
			mp[i][a[i][j]]=j;
			z[aa].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(z[i].size()>=2){
			for(int j=0;j<z[i].size();j++){
				for(int k=j+1;k<z[i].size();k++){
					int st=z[i][j],ed=z[i][k];
					dis[st][ed]=min(dis[st][ed],(ll)((ll)t[st][mp[st][i]]+(ll)t[ed][mp[ed][i]]));
					dis[ed][st]=dis[st][ed];
				}
			}
		}
	}
	floyd();
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			write(dis[i][j]);
			putchar(32);
		}
		putchar(10);
	}
	*/
	while(q--){
		xr=read(),yr=read(),ans=LONG_LONG_MAX;
		for(int st:z[xr]){
			for(int ed:z[yr]){
				ans=min(ans,dis[st][ed]+(ll)((ll)t[st][mp[st][xr]]+(ll)t[ed][mp[ed][yr]]));
			}
		}
		write(ans+(ll)w[xr]+(ll)w[yr]);
		putchar(10);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/
