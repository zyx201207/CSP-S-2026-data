#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ps putchar(' ')
#define pt putchar('\n')
const ll N=5e5+7;
void in(ll &num){
	ll k=1,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	num=k*f;
	return;
}
void ot(ll num){
	if(num<0) putchar('-'),num*=-1;
	if(num>9) ot(num/10);
	putchar(num%10+'0');
	return;
}
void out(ll num){
	ot(num),ps;
	return;
}
ll n,m;
ll a[N],ltp=1,sum=0,maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	in(n),in(m);
//	out(n),pt;
	for(ll i=1;i<=n;i++) in(a[i]);
	stable_sort(a+1,a+n+1);
	a[0]=a[ltp];
	for(ll i=1;i<=n;i++){
		sum+=(i-ltp)*(a[i]-a[i-1]);
		while(sum>m&&ltp<=i) sum-=(a[i]-a[ltp]),ltp++;
		maxn=max(maxn,i-ltp+1);
	}
	out(maxn);
	return 0;
}
/*
cd C:\Users\Administrator\Desktop\GD-S01884\crystal
fc /w /n crystal.out crystal1.ans
*/
