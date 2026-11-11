#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define ff(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
long long a,b,c[500001],f[500001],s=0;
long long read(){
	int f=1;
	long long x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0)x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	a=read(),b=read();
	f(i,1,a,1)c[i]=read();
	s=0;
	sort(c+1,c+a+1);
	long long l=0,r=a+1,mid;
	while(l<r){
		mid=(l+r)/2;
		long long s1=0,s2=b;
		f(i,1,mid-1,1)f[i]=abs(c[mid]-c[i]);
		ff(i,mid,1,1)if(s2>=f[i]&&c[i]+f[i]==c[mid])s2-=f[i],s1++;
		if(s1<s)r=mid-1;
		else l=mid+1;
		s=max(s,s1);
		cout<<s<<endl;
	}
	cout<<s;
	return 0;
}
