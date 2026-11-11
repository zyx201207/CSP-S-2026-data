#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int dis[N],n,t;
ll d,a[N],ans=0,s[N],cnt[N];
ll read(){
	ll s=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
void solve(int l,int r){
	int j1=l,j2=l;
	cnt[l]=1,dis[l]=0;s[l]=1;s[l-1]=0;
	for(int i=l+1;i<=r;i++){
		while(j1<=i&&a[i]-a[j1]>d) j1++;
		dis[i]=dis[j1]+1;
		if(j1<=j2){
			cnt[i]=s[j2]-s[j1-1];
		}
		else{
			j2=j1;
			while(j2<i&&dis[j2]==dis[j2+1]) j2++;
			cnt[i]=s[j2]-s[j1-1];
		}
		//cout<<i<<" "<<j1<<" "<<j2<<" "<<cnt[i]<<"\n";
		s[i]=s[i-1]+cnt[i];
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();t=read();
	while(t--){
		ans=0;
		n=read(),d=read();
		int fl=0;
		//cout<<n<<" "<<d<<endl;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fl=1;
		}
		if(!fl){
			solve(1,n);
			for(int i=2;i<=n;i++) if(cnt[i]==2){
				ans+=n-i+1;
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++) cnt[j]=dis[j]=s[j]=0;
			//cout<<i<<endl;
			solve(i,n);
			for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<endl;
	}
}
/*0 1
6 2 -2 -1 0 1 5 8*/
