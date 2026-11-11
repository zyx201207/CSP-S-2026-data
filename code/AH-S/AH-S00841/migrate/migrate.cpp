#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,k,a[N],xz[N];
int cf[N],td[N];
void mj(int s){
	if(s==n) return;
	int i=s+1;
	while((a[i]-a[s])<=k&&i<=n){
		xz[i]+=xz[s];
		cout<<i<<endl;
		i++;
	}
	i--;
	if(i!=s) mj(i);
}
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	int T2;
	T2=read();
	T=read();
	while(T--){
		int ans=0;
		n=read();
		k=read();
		for(int i=1;i<=n;i++) a[i]=read(),cf[i]=a[i]-a[i-1];
		int cnt=1;
		while(a[cnt]-a[1]<=k) cnt++;
		cnt--;
		td[1]=cnt;
		for(int i=2;i<=n;i++){
			cnt-=cf[i];
			while(a[cnt]-a[i]<=k&&cnt<=n) cnt++;
			cnt--;
			td[i]=cnt;
		}
		for(int i=1;i<=n;i++){
			xz[i]=1;
			mj(i);
			for(int j=i;j<=n;j++){
				if(xz[j]==2) ans++;
				xz[j]=0;
			}
			cout<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
