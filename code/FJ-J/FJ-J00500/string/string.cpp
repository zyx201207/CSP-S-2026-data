#include <bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int read(){
	char c=getchar();
	int x=0;bool flag=false;
	while(c>'9' || c<'0'){
		if(c=='-') flag=true;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return flag ? -x : x;
}
char readc(){
	char c=getchar();
	while(c>'z' || c<'a') c=getchar();
	return c;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+5;
int a[N], cnt[N];char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[i]=readc();
		cnt[i]=a[i];
	}
	int ans=0;
	for(int l=1,r=n;l<r;){
		if(cnt[l]==cnt[r]){
			if(c[l]==c[r]){
				cnt[l]=0;cnt[r]=0;
				l++;r--;
			}
			else{
				ans+=cnt[l];
				cnt[l]=0;cnt[r]=0;
				l++;r--;
			}
		}
		else if(cnt[l]>cnt[r]){
			if(c[l]==c[r]){
				cnt[l]-=cnt[r];
				cnt[r]=0;
				r--;
			}
			else{
				ans+=cnt[r];
				cnt[l]-=cnt[r];
				cnt[r]=0;
				r--;
			}
		}
		else{
			if(c[l]==c[r]){
				cnt[r]-=cnt[l];
				cnt[l]=0;
				l++;
			}
			else{
				ans+=cnt[l];
				cnt[r]-=cnt[l];
				cnt[l]=0;
				l++;
			}
		}
	}
	write(ans);
	return 0;
}
