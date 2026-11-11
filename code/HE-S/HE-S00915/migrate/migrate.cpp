#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll C,T,n,d,f,a[2000005],k,ans;

ll read(){
	ll f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
void out(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10)putchar(x+'0');
	else{
		out(x/10);
		putchar(x%10+'0');
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();
	T=read();
	while(T--){
		n=read();
		d=read();
		ans=0;
		for(ll i=1;i<=n;i++)a[i]=read();
		for(ll i=1;i<=n-3;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d){
				f=2;
				k=i+2;
				ans++;
			}
			else{
				f=1;
				if(a[i+3]-a[i]<=d)k=i;
				else k=i+2;
			}
			for(ll j=i+4;j<=n;j++){
				if(f==1){
					if(a[j]-a[k]>d){
						ll Q=k;
						f=0;
						for(ll w=j-1;w>Q;w--){
							if(a[j]-a[w]>d)break;
							f++;
						}
						k=j-1;
						if(f==2)ans++;
					}
				}
				else{
					if(a[j]-k<=d){
						ll W=f;
						f=1;
						for(ll w=2;w<=W;w++){
							if(a[j]-a[w]>d)break;
							f++;
						}
						if(f==2)ans++;
					}
					else{
						if(f>=3)break;
						k=j-1;
						int E=f,R=k;
						for(ll w=j-1;w>R;w--){
							if(a[j]-a[w]>d)break;
							f+=E;
						}
						k=j-1;
						if(f==2)ans++;
					}
				}
			}
		}
		out(ans);
		putchar('\n');
	}
	return 0;
}
