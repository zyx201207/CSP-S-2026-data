#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

int n,m,ans;
int a[519810];
int s[598100];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(); m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
			
		}
		ans=max(ans,i-l+1);
	}
	write(ans);
	return 0;
}
