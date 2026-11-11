#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int n,m,a[N],ans;
bitset<N>s[40],anss,f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		for(int j=31;j>=0;j--){
			if((a[i]>>j)&1){
				s[j][i]=1;
			}
		}
	}
	for(int j=31;j>=0;j--){
		if(s[j].count()>=m){
			if(anss.count()==0)anss=s[j];
			else{
				f=anss;
				anss&=s[j];
				if(anss.count()<m){
					anss=f;
					break;
				}
			}
		}
	}
	for(int i=1,j=1;i<=n&&j<=m;i++){
		if(anss[i]){
			if(!ans)ans=a[i];
			else ans&=a[i];
			j++;
		}
	}
	write(ans);
}
