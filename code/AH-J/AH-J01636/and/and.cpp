#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[200005],m;
char c[200005][32];
bool b[200005][32];
int res[55];
bool vst[55];
LL ans=0;
void DFS(int h,int index) {
	if(h==m) {
		LL tmp=res[1];
		for(int i=2;i<=h;++i)
		tmp&=res[i];
		ans=max(ans,tmp);
		return;
	}
	for(int i=h+1;i<=n;++i) {
		if(!vst[i]) {
			res[h+1]=a[i];
			vst[i]=1;
			DFS(h+1,i);
			vst[i]=0;
		}
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		//for(int j=31;j>=0;--j)
		//	c[i][31-j]='0'+(bool)(a[i]&(1<<j));
		//c[i][32]='\0';
	}
	/*sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		for(int j=31;j>=0;--j)
			c[i][31-j]='0'+(bool)(a[i]&(1LL<<j)),b[i][31-j]=c[i][31-j]-'0';
		c[i][32]='\0';
		cout<<c[i]<<"\n";
	}*/
	if(m==1) {
		for(int i=1;i<=n;++i)
			ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n) {
		LL tmp=a[1];
		for(int i=2;i<=n;++i) {
			tmp&=a[i];
		}
		cout<<tmp;
	}
	else {
		for(int i=1;i<=n;++i){
			vst[i]=1;
			res[1]=a[i];
			DFS(1,i);
		}
		cout<<ans;
	}
	return 0;
}
