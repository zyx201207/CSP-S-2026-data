#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=2e5+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
	return ;
}
char c[N];
int a[N];
void solve(){
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[i]=getchar();
	}
	int l=1,r=n;ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	if(sum%2==0){
		sum/=2;
		for(int i=1;i<=n;i++){
			if(sum<a[i]){
				ll tmp=a[i]-sum;
				if(tmp<sum)a[i]-=tmp*2,l=i,r=i+1;
				else if(tmp==sum)a[i]=0,l=i-1,r=i+1;
				else a[i]-=sum*2,l=i-1,r=i; 
				break;
			}else if(sum==a[i]){
				l=i,r=i+1;
				break;
			}else sum-=a[i];
		}
	}else{
		sum=(sum+1)/2;
		for(int i=1;i<=n;i++){
			if(sum<a[i]){
				a[i]--;sum--;
				ll tmp=a[i]-sum;
				if(tmp<sum)a[i]-=tmp*2,l=i,r=i+1;
				else if(tmp==sum)a[i]=0,l=i-1,r=i+1;
				else a[i]-=sum*2,l=i-1,r=i;
				break;
			}else if(sum==a[i]){
				a[i]--;
				l=i,r=i+1;
				if(a[i]==0)l--;
			}else sum-=a[i];
		}
	}
	ll ans=0;
	while(l!=0&&r!=n+1){
		if(a[l]>a[r]&&c[l]!=c[r])ans+=a[r],a[l]-=a[r],r++;
		else if(a[l]>a[r]&&c[l]==c[r])a[l]-=a[r],r++;
		else if(a[l]==a[r]&&c[l]!=c[r])ans+=a[r],l--,r++;
		else if(a[l]==a[r]&&c[l]==c[r])l--,r++;
		else if(a[l]<a[r]&&c[l]!=c[r])ans+=a[l],a[r]-=a[l],l--;
		else if(a[l]<a[r]&&c[l]==c[r])a[r]-=a[l],l--;
	}
	write(ans);
	return ;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
/*
3
2 a
2 b
1 c
*/
