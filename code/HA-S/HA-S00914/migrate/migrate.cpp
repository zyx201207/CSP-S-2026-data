#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int read(){
	int x=0,f=1;
	char c = getchar();
	while(c<'0'||c>'9') f = (c=='-')?(-1):(f),c = getchar();
	while(c>='0'&&c<='9') x = (x<<1) + (x<<3) + (c^48),c = getchar();
	return x*f;
}
void write(int x){
	if(x>9) write(x/10);
	if(x<0) putchar('-'),x = -x;
	putchar(x%10^48);
}
ll c,t;
ll x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		int n=read(),d=read();
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(x[i]<0)sum++;
		}
		if(sum>=n>>1){
			for(int i=1;i<=n;i++){
				ans+=x[i];
			}
			write(abs(ans));
			putchar('\n');
			continue;
		}
		ans=(n%2==0)?(1):(2);
		write(ans);
		putchar('\n');
	}
	
	return 0;
}

	
