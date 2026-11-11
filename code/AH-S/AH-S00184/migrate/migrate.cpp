#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	char c;
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
const int N=2e6+5;
int c,T;
int x[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--){
		int n,d,dx;
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		dx=x[n]-x[n-1];
		if(d<2*dx) cout<<"0\n";
		else{
			int a=d/dx;
			int ans=n-(2*a-1);
			if(ans<0) ans=0;
			cout<<ans<<endl;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
