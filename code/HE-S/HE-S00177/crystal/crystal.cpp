#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int input();
void print(int x);
constexpr int N=5e5+1;
int a[N],ans;
signed main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=input(),m=input();
	bool f=1;
	for (int i = 1;i<=n;i++){
		a[i]=input();
		if (a[i]!=i) f=0;
	}
	if (f){
		for (int i = n;i>=1;i--){
			if (a[n]-a[i]>m) break;
			m-=(a[n]-a[i]);
			++ans;
		}
		print(ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for (int i = 1;i<=n;i++){
		int sum=0,x=m;
		while (a[i]==a[i+1]&&i<n) ++i;
		for (int j = i;j>=1;j--){
			if (a[i]-a[j]<=x){
				x-=(a[i]-a[j]);
				++sum;
			}
			else break;
		}
		ans=max(ans,sum);
	}
	print(ans);
	return 0;
}
inline int input(){
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if (x<0){
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
