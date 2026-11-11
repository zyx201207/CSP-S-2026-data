#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long n,a[N],b[N],l,ans,tmp;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		b[i] = b[i-1] + a[i];
		l += a[i];
	}
	long long y = (l+1)/2,x = lower_bound(b+1,b+1+n,y) - b;tmp = a[x];
	if(l%2==0) a[x] -= max(0*1ll,min(y-b[x-1],b[x]-y)*2);
	else a[x] -= max(0*1ll,min(y-1-b[x-1],b[x]-y)*2+1);
	l = l-tmp+a[x];
	ans = l/2;
	int i = 0,j = n+1;
	long long sumi=0,sumj=0;
	while(i+1<j){
		while(sumi<l/2&&sumi<=sumj){
			sumi += a[++i];
			if(c[i]==c[j]){
				if(sumi<=sumj) ans-=a[i];
				else ans -= a[i]-(sumi-sumj);
			}
		}
	//	cout << sumi << ' ' << ans << ' ' << sumj << endl;
		while(sumj<l/2&&sumj<=sumi){
			sumj += a[--j];
			if(c[i]==c[j]){
				if(sumj<=sumi) ans-=a[j];
				else ans -= a[j]-(sumj-sumi);
			}
		}
		//cout << sumi << ' ' << ans << ' ' << sumj << endl;
	}
	cout << ans;
	return 0;
} 
