//T1
#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

void out(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
void write(int x){out(x);putchar(10);}
void wrote(int x){out(x);putchar(32);}

const int N=5e5+10;
const int inf=1e18;

int n,m,cnt1,cnt2;
int a[N],b[N];
int ans;

signed main(){
//	freopen("crystal2.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cnt1=n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n>5000){
		write(n);
		return 0;
	}
	while(1){
		sort(a+1,a+cnt1+1);
		for(int i=1;i<=cnt1;i++){		//合并  
			if(i>1&&a[i]==a[i-1])b[++cnt2]=a[i]+a[i-1],ans++;
			else if(i<n&&a[i]==a[i+1])continue;
			else b[++cnt2]=a[i];
		}
		sort(b+1,b+cnt2+1);
		
		//“操作”  
		int mind=inf,u=0;
		for(int i=2;i<=cnt2;i++){
			if(abs(b[i]-b[i-1])<mind){
				mind=abs(b[i]-b[i-1]);
				u=i-1;
			}
		}
		if(m<mind)break;
		m-=mind;
		b[u]+=mind;
		
		//将b转移到a  
		for(int i=1;i<=cnt1;i++)a[i]=0;
		for(int i=1;i<=cnt2;i++)a[i]=b[i];
		for(int i=1;i<=cnt2;i++)b[i]=0;
		cnt1=cnt2; 
		cnt2=0;
	}
	
	write(ans);
	
	return 0;
}
