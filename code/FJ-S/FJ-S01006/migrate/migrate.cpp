#include<bits/stdc++.h>
using namespace std;
long long id,T,n,d,cnt,ans,x,y,a[2000005],p[2000005],pp[2000005],p_[2000005],pp_[2000005],dp[2000005],dp_[2000005];
long long read(){
	long long ans=0;
	char c=0;
	bool f=0;
	while(c<'0'||c>'9')c=getchar(),f|=(c=='-');
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return f?-ans:ans;
}
void write(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	id=read(),T=read();
	if(id==11||id==12){
		while(T--){
			n=read(),d=read(),ans=0;
			for(int i=1;i<=n;i++)a[i]=read();
			if(n<=3)putchar('0'),putchar('\n');
			else{
				d/=(a[2]-a[1]);
				if(d<=1)putchar('0'),putchar('\n');
				else write(max(n-2*d+1,0ll)),putchar('\n');
			}
		}
		return 0;
	}
	while(T--){
		n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),p[i]=pp[i]=0,dp[i]=dp_[i]=1;
		cnt=1,a[n+1]=a[n]+2*d,a[0]=a[1]-2*d;
		for(int i=1;i<=n;i++){
			while(cnt<i&&a[i]-a[cnt]>d)cnt++;
			if(a[i+1]-a[cnt]>d)p[i]=cnt;
			p_[i]=cnt;
		}
		cnt=n;
		for(int i=n;i;i--){
			while(cnt>i&&a[cnt]-a[i]>d)cnt--;
			if(a[cnt]-a[i-1]>d)pp[i]=cnt;
			pp_[i]=cnt;
		}
		for(int i=n;i;i--)dp[p[i]]+=dp[i];
		for(int i=1;i<=n;i++)dp_[pp[i]]+=dp_[i];
		for(int i=2;i<n-1;i++)
		    if(p_[i+2]>p_[i+1]&&p_[i+1]<i&&pp_[i]>pp_[i-1]&&pp_[i]>i+1)
		    	ans+=(p_[i+2]-p_[i+1]-1+dp_[p_[i+1]])*(pp_[i]-pp_[i-1]-1+dp[pp_[i]]);
		write(ans),putchar('\n');
	}
	return 0;
}
