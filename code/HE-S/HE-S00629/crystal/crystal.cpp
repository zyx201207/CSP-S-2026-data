#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,id;
int ans=0;
int a[N];
bool f;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int xdsdg[65];
void write(int x){
	int tot=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0){
		putchar('0');return;
	}
	while(x){
		xdsdg[++tot]=((x%10)^48);
		x/=10;
	}
	for(int i=tot;i;i--){
		putchar(xdsdg[i]);
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		int maxn=0;
		bool f=0;
		for(int i=n;i;i--){
			int now=a[i],sum=0,id=0;
			for(int j=i-1;j;j--){
					sum+=now-a[j];
				if(sum>m){
					id=j;break;
				}
			}
			maxn=max(maxn,i-id);
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans+=(a[n]-a[i]);
	}
	if(ans<=m){
		f=1;
		cout<<n;
		return 0;
	}
	for(int i=n-1;i>1;i--){
		int d=a[i+1]-a[i];
		ans-=i*d;
//		cout<<ans<<" ";
		if(ans<=m){
			id=i;
			f=1;break;
		}
	}
	if(!f)id=1;
	cout<<id;
	return 0;
}
