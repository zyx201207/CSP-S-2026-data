#include<bits/stdc++.h>
using namespace std;
#define int long long
int read();
void write(int x);
int n;
int m;
int const D=5e5+50;
int a[D];
int s[D];
int k[D];
int ans;
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
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		k[i]=a[i]*i-s[i];
	}
	int t;
	for(int i=n;i>=1;i--){
		if(m>=k[i]){
			t=i;
			break;
		}
	}
	ans=t;
	for(int i=t+1;i<=n;i++){
		int l=1,r=i-t+1;
		int u=D;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				u=min(u,mid);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		if(u!=D)ans=max(ans,i-u+1);
	}
	write(ans);
	return 0;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
