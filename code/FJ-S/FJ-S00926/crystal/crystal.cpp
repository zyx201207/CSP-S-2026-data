#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &x){
	bool f=0;
	char ch;
	x=0;
	while(ch=getchar(),(ch<'0'||ch>'9')) if(ch=='-') f=1;
	while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	if(f) x=-x;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar((x%10)+48);
}
const int N=500010;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=i&&(a[i]-a[j-1]+m<(a[i]-a[i-1])*(i-j+1))) j++;
		ans=max(ans,i-j+1);
	}
	print(ans);
	return 0;
}

