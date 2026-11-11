#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans;
struct it{
	long long now;
	long long num;
}l,r;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	l={1,1},r={n,1};
	for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
	if(n&1)
		while(r.now!=l.now){
			if(c[l.now]!=c[r.now]){
				long long a1=a[l.now]-l.num+1;
				long long a2=a[r.now]-r.num+1;
				if(a1<a2){
					r.num+=a[l.now]-l.num+1;
					ans+=a[l.now]-l.num+1;
					l.now++;
					l.num=1;
				}
				if(a1==a2){
					l.now++;
					r.now--;
					l.num=1;
					r.num=1;
					ans+=a1;
				}
				if(a1>a2){
					l.num+=a[r.now]-r.num+1;
					ans+=a[r.now]-r.num+1;
					r.now--;
					r.num=1;
				}
			}
			else{
				long long a1=a[l.now]-l.num+1;
				long long a2=a[r.now]-r.num+1;
				if(a1<a2){
					r.num+=a[l.now]-l.num+1;
					l.now++;
					l.num=1;
				}
				else{
					l.num+=a[r.now]-r.num+1;
					r.now--;
					r.num=1;
				}
			}
		}
	else{
		while(r.now-l.now>1){
			if(c[l.now]!=c[r.now]){
				long long a1=a[l.now]-l.num+1;
				long long a2=a[r.now]-r.num+1;
				if(a1<a2){
					r.num+=a1;
					ans+=a1;
					l.now++;
					l.num=1;
				}
				if(a1==a2){
					l.now++;
					r.now--;
					l.num=1;
					r.num=1;
					ans+=a1;
				}
				if(a1>a2){
					l.num+=a2;
					ans+=a2;
					r.now--;
					r.num=1;
				}
			}
			else{
				long long a1=a[l.now]-l.num+1;
				long long a2=a[r.now]-r.num+1;
				if(a1<a2){
					r.num+=a[l.now]-l.num+1;
					l.now++;
					l.num=1;
				}
				else{
					l.num+=a[r.now]-r.num+1;
					r.now--;
					r.num=1;
				}
			}
		}
		if(c[l.now]!=c[r.now]){
				long long a1=a[l.now]-l.num+1;
				long long a2=a[r.now]-r.num+1;
				if(a1<a2){
					r.num+=a1;
					ans+=a1;
					l.now++;
					l.num=1;
				}
				if(a1==a2){
					l.now++;
					r.now--;
					l.num=1;
					r.num=1;
					ans+=a1;
				}
				if(a1>a2){
					l.num+=a2;
					ans+=a2;
					r.now--;
					r.num=1;
				}
			}
	}
	printf("%lld",ans);
	return 0;
}
