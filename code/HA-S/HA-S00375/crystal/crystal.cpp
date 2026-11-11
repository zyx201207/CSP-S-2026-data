#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){int x;scanf("%lld",&x);return x;}
bool cmp(int a,int b){return a<b;}
const int N=5e5+10;
int a[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read(),cnt=0,cnt1=0;
	bool f=false;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}else if(n==2){
		int c=read(),d=read();
		if(abs(c-d)<=m) cout<<2<<endl;
		else cout<<1<<endl;
		return 0;	
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i==1) cnt=a[i];
		if(i==2) cnt1=a[i]-cnt,cnt=a[i];
		if(i>=2){
			if(a[i]-cnt==cnt1){
				cnt=a[i];
			}else f=1;
		}
	}
	if(!f){
		int anss=0;
		for(int i=1;i<=n;i++){
			anss+=(i*cnt);
			if(anss>m){
				cout<<i-1ll;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0; 
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0ll;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int summ=sum[j]-sum[i-1];
			int id=j-i+1;
			if((summ+m)/id>=(int)a[j]) ans=max(ans,id);
		}
	}
	cout<<ans<<endl;
	return 0;
}
