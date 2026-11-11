#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int read() {
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int maxn=2e5+5,maxw=31;

int n,m,a[maxn];

bool mark[maxn][maxw];
int sum[maxw];

int ans;

signed main() {

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	n=read(),m=read();
	
	for(int i=1;i<=n;i++) 
		a[i]=read();
	
	sort(a+1,a+1+n,greater<int>());
	
	for(int i=1;i<=n;i++) 
		for(int j=0;j<maxw;j++)
			if(a[i]&(1ll<<j)) mark[i][j]=true,sum[j]++;
	
	for(int j=maxw-1;j>=0;j--) {
		
		if(sum[j]<m) continue;
		
		bool flag=true;
		int cnt=0;
		
		for(int i=1;i<=n;i++) {
			
			if(mark[i][j]&&flag) ans=a[i],flag=false;
			else if(mark[i][j]) ans&=a[i];
			
			if(mark[i][j]) {
				
				++cnt;
				if(cnt==m) break;
			}
		}
		
		write(ans);
		
		return 0;
	}
	
	write(0);

	return 0;
}
