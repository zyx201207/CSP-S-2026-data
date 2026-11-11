#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,cnt,ans,a[N],mp[N],nw[N];
ll read(){
	char ch;ll s=0,w=1;
	while((ch=getchar())>'9' || ch<'0') if(ch=='-') w=-1;
	while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) mp[i]=1;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=29;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++) nw[j]=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1){
				nw[j]=1;
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!mp[j] && nw[j]){
					nw[j]=0;
					cnt--;
				}
			}
			if(cnt>=m){
				for(int j=1;j<=n;j++) mp[j]=nw[j];
				ans|=(1<<i);
			}
		}
	}
	write(ans);
	return 0;
}
