#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define ff(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","r",stdout);
	long long a,b;
	cin>>a>>b;
	f(i,1,b,1){
		cout<<i<<endl;
	}
	return 0;
}

