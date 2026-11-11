#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

int n,d,ans;
int a[2019810]; 
int pre[2019810],nxt[2019810],sp[2019810],sn[2019810];
int f[2019810];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	read(); int T=read();
	while(T--){
		n=read(); d=read(); ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		int top=1;
		for(int i=1;i<=n;i++){
			while(a[i]-a[top]>d)top++;
			pre[i]=top;
		}
		top=n;
		for(int i=n;i>=1;i--){
			while(a[top]-a[i]>d)top--;
			nxt[i]=top;
		}
		
//		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<pre[i]<<" "<<nxt[i]<<"!\n"; 
//		}
		
		memset(sp,0,sizeof(sp));
		memset(sn,0,sizeof(sn));
		memset(f,0,sizeof(f));
		
		f[0]=-99; f[n+1]=-99;
		
		for(int i=1;i<=n;i++){
			sp[nxt[i]]++;
			if(nxt[i-1]!=nxt[i])sp[nxt[i]]+=sp[i];
			if(nxt[i]>i+1)f[nxt[i]]++;
			if(nxt[i]>i+1&&pre[nxt[i]]==i&&pre[nxt[i]-1]==i)f[nxt[i]]+=sp[i];
		}
		for(int i=n;i>=1;i--){
			sn[pre[i]]++;
			if(pre[i+1]!=pre[i])sn[pre[i]]+=sn[i];
			if(pre[i]<i-1)ans+=f[pre[i]+1];
			if(pre[i]<i-1&&nxt[pre[i]]==i&&nxt[pre[i]+1]==i)ans+=sn[i]*f[pre[i]+1];
		}
		
		
		write(ans); putchar('\n');
	}
	
	return 0;
}

// 发现合法对的形式一定是 唯一路径-另一个短合法对-唯一路径

// 最短合法对一定为两步到位 
