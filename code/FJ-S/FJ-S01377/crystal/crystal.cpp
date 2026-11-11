#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T &x){
	x=0;bool bj=0;char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')bj=1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+(s^48);
		s=getchar();
	}
	if(bj)x=-x;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
long long n,m,a[500005],js[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);js[0]=0;
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
//	cout<<a[315275]<<"\n"<<a[313324]<<"\n";
//	for(int i=313321;i<=315279;i++){
//		cout<<a[i]<<" ";
//		if(i%10==0)cout<<"\n";
//	}
//	cout<<"\n";
	for(int i=1;i<=n;i++)js[i]=a[i]+js[i-1];
	for(int i=1;i<=n;i++){
//		if(i==315275||i==313324)cout<<a[i]*i*1ll-js[i]<<" "<<m<<"\n";
		if(a[i]*i*1ll-js[i]<=m){
			sum=i;
		}
	}
	write(sum);
	return 0;
}
