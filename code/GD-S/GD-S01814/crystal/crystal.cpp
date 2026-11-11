#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define ull unsigned long long
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n;
ull m;
int a[500005];
ull sub[500005];
ull sum=1;
int ans;
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0)return;
	write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sub[i]=abs(a[i]-a[i-1]);
	}
	for(int i=1;i<n;i++){
		if(sub[i+1]*sum<=m){
			m-=sum*sub[i+1];
			ans=a[i+1];
			sum++;
		}else{
			break;
		}
	}
	write(sum);
	return 0;
}
