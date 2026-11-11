/*
1.是否开long long，空间够不够？
2.数组大小开到上限+50了吗？
3.边数组是否够？
4.多测清空？
5.多测读完数据再特判？
6.跑过极限数据？
7.暴力分，特殊性质打满了吗？
8.freopen不要注释！！！
*/
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+50;
int n,m,a[N],s[N],r=1,ans;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+48);
	else write(x/10),putchar(x%10+48);
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int l=1;l<=n;l++){
		while(r+1<=n&&(r+1-l+1)*a[r+1]-(s[r+1]-s[l-1])<=m)r++;
		ans=max(ans,r-l+1);
	}
	write(ans);
	return 0;
}
