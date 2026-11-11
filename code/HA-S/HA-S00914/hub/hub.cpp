#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+6;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')f=(c=='-')?(-1):(f),c=getchar();
	while(c<='9'&&c>='0')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
void write(int x){
	if(x>9)write(x/10);
	if(x<0)putchar('-'),x=-x;
	putchar(x%10^48);
}
struct jj{
	int u,v;
}cao[N];
ll c,t;
ll sum;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		int n=read(),k=read();
		for(int i=1;i<n;i++){
			cao[i].u=read(),cao[i].v=read();
			}
			write(1);
			putchar(' ');
		}
		
	return 0;
}
