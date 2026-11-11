#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110000],c[11000],maxn=0,mm,ii=1e18;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);mm=max(mm,a[i]);ii=min(ii,a[i]);
	}sort(a+1,a+n+1);
	if(mm-ii>10000){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof c);
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i]==a[j])cnt++;
			else{
				c[abs(a[i]-a[j])]++;
			}
		}
		ll g=m;
		for(int i=1;i<=10000;i++){
			if(g==0)break;
			if(c[i]*i<=g){
				cnt+=c[i];
				g-=c[i]*i;
			}else{
				if(i>g)break;
				ll f=g/i;
				cnt+=f;
				break;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
