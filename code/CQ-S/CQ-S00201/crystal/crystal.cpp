#include <bits/stdc++.h>
using namespace std;
int n,l=1,r=1,ans=1;
long long int m,a[500010],sum,q[500010],mi=LLONG_MAX;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
long long int read1(){
	long long int x=0,f=1;
	char ch=getchar();
	while(!(ch>='0' and ch<='9')){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read1();
	for(int i=1;i<=n;i++){
		a[i]=read1();
		mi=min(mi,a[i]);
	}
	sort(a+1,a+n+1);
	mi*=-1;
	for(int i=1;i<=n;i++){
		a[i]+=mi;
		q[i]=q[i-1]+a[i]; 
	}
	while(r<=n and l<=r){
		if(((a[r]*(r-l+1))-(q[r]-q[l-1]))<=m){
			ans=max(ans,(r-l+1));
			r++;
		}
		else l++;
	} 
	cout<<ans;
	return 0;
}
/*
我是CQ-J00241 or 281
J组我没写文件操作
这一次，我要把文件操作写上去
V我50，听听我的写文件操作计划
我是洛谷ykj110，我是区
战争雷霆日系是最好玩的系
15:04  T1大样例全过，幸好昨晚豆老师给我讲了双指针
17:04  两个小时打T2打炸了，得了滚木分，小样例全过，大样例全错，希望有人能帮我解答一下 
17:52  T3拿了8分 
18:22  ijk混淆卡了半个小时，T3拿了8分，116，到此为止了 
*/
