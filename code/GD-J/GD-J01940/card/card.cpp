#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],top,s[500005],b[500005],cnt[500005];
bool flag[3005];
void solve1(){
	for(int i=1;i<=n;i++){
		top=0;
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(!flag[a[j]])s[++top]=a[j],flag[a[j]]=1;
			else{
				while(s[top]!=a[j]){
					flag[s[top]]=0;
					top--;
				}
			}
		}
		while(top){
			ans[s[top]]++;
			top--;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}
void solve2(){
	if(a[1]!=a[n])printf("1 1");
	else{
		if(a[1]==1)printf("1 0");
		else printf("0 1");
	}
}
void solve3(){
	//可能会错，与solve1分开写 
	int real_n=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[++real_n]=a[i];
			cnt[real_n]=1;
		}else cnt[real_n]++;
	}
	n=real_n;
	for(int i=1;i<=n;i++)a[i]=b[i];
	for(int i=1;i<=n;i++){
		top=0;
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(!flag[a[j]])s[++top]=a[j],flag[a[j]]=1;
			else{
				while(s[top]!=a[j]){
					flag[s[top]]=0;
					top--;
				}
			}
		}
		while(top){
			ans[s[top]]+=cnt[i];
			top--;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}
void solve4(){
	for(int i=1;i<=n;i++)
		if(a[i]!=a[i+1])ans[a[i]]=i;
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=5000)solve1();
	else if(m<=2)solve2();
	else if(m<=3000)solve3();
	else solve4();
	return 0;
}
/*
感言：
其实我本来不打算写的
但是还有15分钟没事干 ，就写写吧
今年应该是最后一次参加J组了
还记得两年前那个在考场上紧张得忘记freopen怎么写的少年
也记得一年前CSPS与一等奖擦肩而过的遗憾
今天本想着是最后的绝唱，要冲此J组AK 
结果估分只有372
为什么我的眼中常含泪水？因为我对OI爱得深沉。。。。。。 
永别了，CSPJ。。。。。。 
P.S.其实我才初二，只是明年想只打S组，我要上迷惑行为大赏！！！！！！ 
*/
