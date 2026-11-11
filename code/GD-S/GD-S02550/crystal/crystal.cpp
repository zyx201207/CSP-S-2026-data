#include<bits/stdc++.h>
#define int __int128
using namespace std;
void read(int &x){
	char y=getchar();
	bool fl=0;
	while(!('0'<=y && y<='9')){
		if(y=='-')fl=1;
		y=getchar();
	}
	x=0;
	while('0'<=y && y<='9'){
		x=(x<<3)+(x<<1)+y-'0';
		y=getchar();
	}
	if(fl)x=-x;
}
#define out(x) putchar(x)
void writ(const int &x){
	if(x<10){
		out(x+'0');
		return ;
	}
	writ(x/10);
	out(x%10+'0');
}
void write(const int &x){
	if(x==0)out('0');
	else if(x<0){
		out('-');
		writ(-x);
	}else writ(x);
}
const int N=5e5+5;
int n,m,a[N],sum[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	for(int i=1,j=1;i<=n;i++){
//		cout<<m+sum[i]-sum[j-1]<<' '<<a[i]<<' '<<(i-j+1)<<'\n';
//		write(i);out(' ');
//		write(j);out('\n');
//cout<<"QAQ";
		while(m+sum[i]-sum[j-1]<a[i]*(i-j+1) && j<=n)j++;
		ans=max(ans,i-j+1);
//		write(i);out(' ');
//		write(j);out('\n');
	}
	write(ans);
	return 0;
}//I will win this game!!!
