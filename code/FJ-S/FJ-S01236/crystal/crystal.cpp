#include<bits/stdc++.h>
//Furry Furry!!!
//XC.Furry
//Bilibili @羲晨是只小蓝龙 
//luogu.com.cn @wuhongkun 
//I`m furry! 
using namespace std;
typedef long long ll;
//ll lmax(ll a,ll b){
//	return a>b?a:b;
//}
bool cmp(ll x,ll y){
	return x<y;
} 
inline ll readl(){
	ll l=1,r=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')l=-l;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		r*=10;
		r+=ch-'0';
		ch=getchar(); 
	}
	return r*l;
}
//inline int read(){
//	int l=1,r=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		if(ch=='-')l=-l;
//		ch=getchar(); 
//	}
//	while(ch>='0'&&ch<='9'){
//		r*=10;
//		r+=ch-'0';
//		ch=getchar(); 
//	}
//	return r*l;
//}
ll n,a[100005],m;
bool check(ll mid){
	ll sum=m;
	for(int i=1;i<mid;i++){
		sum-=a[mid]-a[i];
		if(sum<0)return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=readl();
	m=readl();
	for(int i=1;i<=n;++i)a[i]=readl();
	sort(a+1,a+1+n,cmp);
	ll l=0,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
} 
/*
14:58：T1炸了 ，二分不行，check不对 eeeeeeeeeeee
15:08：接着试 
15:10：决定推翻重写（发现写复杂了）二分应该分个数的 T_T 
15:16：T1 1.0搞定！ 
15:19：T1小样例通过！！！RP++！ 
15:22：T1文件读入输出卡了 
15:36：样例4炸了 
15:45：突然有点想吃猫条喵~（突然发现出大事了，这个算法居然是错的，可以不从最小的开始！） 
15:50：还是不行，炸了，漏洞还在，好像不能用二分啊！？？？ 
15:56：放弃挣扎了 
*/
