//Trick||Treat! Oct31==Dec25?
//why csps-new???
//crystal
//区间DP??
//0 ≤ m ≤ 10^18 ??????????????????? 数位DP?
//???暴力都写错???
#include<iostream>
using namespace std;
long long ans=-0x3f3f3f3f;
// long long crystals[564444];
long long crystals[564444];
long long a[564444];
long long n,m;
long long maxidx=-0x3f3f3f3f;
long long read(){
	long long f=1;
	long long res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		long long kk=ch-48;
		res=res*10+kk;
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void dfs(long long pos,long long cnt){
	if(cnt>m)return;
	if(pos==n){
		long long m1=-0x3f3f3f3f;
		for(long long i=0;i<=maxidx;i++){
			m1=max(m1,crystals[i]);
		}
		ans=max(ans,m1);
		return;
	}
	long long tt=a[pos];
	crystals[tt]--;
	a[pos]++;
	crystals[a[pos]]++;
	maxidx=max(maxidx,a[pos]);
	dfs(pos+1,cnt+1);
	dfs(pos,cnt+1);
	crystals[tt]++;
	crystals[a[pos]]--;
	a[pos]--;
	dfs(pos+1,cnt);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	// long long n,m;
	n=read();
	m=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
		crystals[a[i]]++;
	}
	dfs(1,0);
	print(ans);
}
//16:06 终于给我调出来了神秘crystal的神秘暴力
//接下来就要写个快读快写
//NOI Linux 2.0咋越用越卡？？？？
//16:15 依旧过不去大样例 让我优化一下
//段错误 (核心已转储)
//500000那没办法了 肯定爆栈的