#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int C,T,n,d;
int ans;
int a[N];
int read(){
	int x=0;bool neg=false;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=true;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return neg?-x:x;
}
void write(int x){
	if(x<10){putchar(x+'0');return;}
	write(x/10);
	putchar(x%10+'0');
}
void ts1(){
	ans=0;
	for(int s=1;s<=n;s++){
		int f[1005],c[1005];
		f[s]=0,c[s]=1;
		for(int i=s+1;i<=n;i++) f[i]=0x3f3f3f3f3f3f3f3f;
		int l=s;
		for(int i=s+1;i<=n;i++){
			while(l<i&&a[i]-a[l]>d) l++;
			for(int j=l;j<i;j++){
				if(f[i]>f[j]+1) f[i]=f[j]+1,c[i]=c[j];
				else if(f[i]==f[j]+1) c[i]+=c[j];
			}
			if(c[i]==2) ans++;
		}
	}
	write(ans);putchar('\n');
}
void ts2(){
	//cerr<<a[2]-a[1]<<' '<<d<<'\n';
	ans=0;
	int k=d/(a[2]-a[1]);
	if(k<=1){
		write(0);
		putchar('\n');
		return;
	}
	int K=2*k-1;
	ans=max(0ll,n-K);
	write(ans);putchar('\n');
}
void tsb(){
	ans=0;
	int r[N],l[N];
	l[0]=1;
	for(int i=1;i<=n;i++){
		l[i]=l[i-1];
		while(l[i]<i&&a[i]-a[l[i]]>d) l[i]++;
	}
	r[n+1]=n;
	for(int i=n;i>=1;i--){
		r[i]=r[i+1];
		while(r[i]>i&&a[r[i]]-a[i]>d) r[i]--;
	}
	for(int i=1;i<=n;i++){
		ans+=min(upper_bound(r+1,r+n+1,l[i]+1),r+i-1)-min(lower_bound(r+1,r+n+1,l[i]+1),r+i-1);
	}
	write(ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),d=read();
		bool Ts2=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) Ts2=0;
		}
		//cerr<<n<<' '<<d<<'\n';
		if(Ts2) ts2();
		else if(n<=5000) ts1();
		else if(C==13||C==14) tsb();
	}
	return 0;
}
