#include<bits/stdc++.h>
using namespace std;
int a[200010];
int s[200010];
char b[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>> b[i];//1a2b3c
		s[i]=s[i-1]+a[i];
	}
	int S=s[n];//6
	int ss=S/2;//3
	int t;
	int tt;
	for(t=1; t<=n; t++) {
		if(s[t]>=ss) {//2
			tt=s[t]-ss;//0
			break;
		}
	}
	if(tt!=0) {

		for(int i=n+1; i>=t+2; i--) {
			a[i]=a[i-1];
			b[i]=b[i-1];
		}
		a[t+1]=tt;
		b[t+1]=b[t];
		a[t]-=tt;
		n++;
	}
	if(S&1) {
		a[t+1]--;
	}
	int ans=0;
	int l=t;//ll所在段 
	int ll=ss;
	int lll=a[l];//本段剩余长度 
	int r=t+1;//rr所在段 
	int rr=ss+1; 
	int rrr=a[r];//本段剩余长度 
	while(l) {
		if(lll>rrr){
			if(b[l]!=b[r]){
				ans+=rrr;
			}
			rr+=rrr-1;
			ll-=rrr-1;
			r++;
			lll-=rrr;
			rrr=a[r];
		}
		else if(lll<rrr){
			if(b[l]!=b[r]){
				ans+=lll;
			}
			ll-=lll-1;
			rr+=lll-1;
			l--;
			rrr-=lll;
			lll=a[l];
		}
		else if(lll==rrr){
			if(b[l]!=b[r]){
				ans+=rrr;
			}
			ll-=lll-1;
			l--;
			lll=a[l];
			rr+=rrr-1;
			r++;
			rrr=a[r];
		}
	}
	cout<<ans;
}
/*
解：
*/
/*
看一看新闻怎么说
好事
也没提我
坏事
也没提我
今天也努力工作
上班也没干活
下班也没干活
跟朋友一起战斗
单排也打不过
开黑也打不过
星期四吃点什么
炸鸡配可乐
汉堡配可乐

平凡浓郁的生活
大吉大利
大吉大利
吹吹风唱唱歌
谢天谢地
谢天谢地
今天有没有爱我
再接再厉
再接再厉
口号要不要来一个
哈撒给！
哈撒给！

平凡浓郁的生活
大吉大利
大吉大利
吹吹风唱唱歌
谢天谢地
谢天谢地
今天有没有爱我
再接再厉
再接再厉
口号要不要来一个
哈撒给！
哈撒给！
哈撒给！
哈撒给！
哈撒给！
哈撒给！
...
哈.

要是说生活挺好吧
爱情是也没有
金钱是也没有
要是说生活不好吧
心情是也不错
身体也不错
保卫我的生活
神仙我也不做
屏幕面前的朋友
今天要快乐，明天要快乐
（万圣快乐！）

平凡浓郁的生活
大吉大利
大吉大利
吹吹风唱唱歌
谢天谢地
谢天谢地
今天有没有爱我
再接再厉
再接再厉
口号要不要来一个
哈撒给！
哈撒给！
*/
