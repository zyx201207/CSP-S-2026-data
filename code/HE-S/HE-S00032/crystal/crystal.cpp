#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll ans=0;
	ll lid=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-lid+1)>(s[i]-s[lid-1])+m){
			lid++;
		}
//		cout<<lid<<'\n'; 
		ans=max(ans,i-lid+1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9
*/
//14:50
//考场电脑时间好像快了5分钟
//现在是14：45吧
//小样例过了 
//14:55
//怎么大样例也全过了
//真这么水？
//输入1 1 1 出了个2
//还好前天打ICPC重现吃了三发罚时 
//lid初始化不对
//最后半个小时回来再查一遍
//rp++ 
//怎么感觉这像原题啊
//我好像还发了篇题解来着
//P16347吗？
//I'm an already_dead_fish
//18:20
//坐标HE应该能进NOIP吧
//QAQ 
