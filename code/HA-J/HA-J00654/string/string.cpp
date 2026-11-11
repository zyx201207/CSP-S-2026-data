#include <bits/stdc++.h>
using namespace std;
int n,a[200010],k=1;
long long cnt=0,tot,ans=0,f=0,t;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d %c",&a[i],&c[i]);
	for(int i=1;i<=n;++i) cnt+=a[i];
	for(int i=1;i<=n;++i){
		f+=a[i];
		if((f+a[i])*2>cnt){
			t=i;break;
		}
	}cnt=0;tot=a[1];
	for(int i=n;i>t&&k<=t;--i){
		cnt+=a[i];
		if(cnt<=tot){
			if(c[i]!=c[k]) ans+=a[i];	
		}
		else{
			if(i==n&&c[i]!=c[k]) ans+=tot;
			if(i!=n&&c[i]!=c[k]) ans+=(a[i]-(cnt-tot));
			while(tot<=cnt){
				if(k==t) break;
				++k;tot+=a[k];
				if(tot<=cnt){
					if(c[i]!=c[k]) ans+=a[k];			
				}
				else{
					if(c[i]!=c[k]) ans+=(a[k]-(tot-cnt));
				}
			}
		}
	}printf("%lld",ans);
	return 0;
}
