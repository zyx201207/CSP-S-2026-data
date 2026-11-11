#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=5e5+10;
int a[N],n,m,sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1,j=0;i<=n;i++){
		sum+=a[i];
		while((i-j)*a[i]-sum>m&&j<i-1)sum-=a[++j];
		ans=max(ans,i-j);
	}
	write(ans);
	return 0;
}
