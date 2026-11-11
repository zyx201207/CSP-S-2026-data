#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x){
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int n,m;
int a[N],lzy[N];
int ans=0;
bool xa=true,xb=true;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]!=i) xa=false;
			if((a[i]-a[i-1])!=(a[2]-a[1])&&(i>2)) xb=false; 
	}
	if(xa){
		for(int i=1;i<=n;i++){
			if((i-1)*i/2<=m){
				ans=i;
			}
			else {
				write(ans);
				return 0;
			}
		}
	}
	if(xb){
		int d=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if((i-1)*i*d/2<=m){
				ans=i;
			}
			else {
				write(ans);
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		lzy[i]=lzy[i-1]+(a[i]-a[i-1])*(i-1);
		for(int j=1;j<=i;j++){
			if(ans>(i-j+1)) break;
			if(lzy[i]-lzy[j]-(j-1)*(a[i]-a[j])<=m){
				ans=max(ans,(i-j+1));
			}
		}
	}
	write(ans);
	return 0; 
}
//5 8
//-3 -1 2 2 7

