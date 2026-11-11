#include<bits/stdc++.h>
using namespace std;
long long read(){long long x;scanf("%lld",&x);return x;}
long long n,m,ans,a[505050],b[505050],left1,right1;
bool pd(int l,int r){
	if(b[r]-b[l-1]+m>=a[r]*(r-l+1))return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	for(int i=2;i<=n;i++){
		left1=1;right1=i-ans;
		int op=1;
		while(op){
			if(!pd(right1,i))break;
			if(pd((right1+left1)/2,i))right1=(right1+left1)/2;
			else left1=(right1+left1)/2+1;
			if(right1==left1){
				op=0;
			}
		}
		if(!op){
			ans=max(ans,i-right1+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
//¶þ·Ö nlog2n
