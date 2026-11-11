#include<bits/stdc++.h>
using namespace std;
long long a[200010],n,m,d[200010],f[200010],h,l,q[200010],r,v,b;
char s[200010],w[200010],g[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>s[i];
		l=l+a[i];
	}
	if(l%2==1) l=l/2+1;
	else l=l/2;
	for(int i=1;i<=n;i++){
		if(h+a[i]>=l){
			d[++v]=l-h;
			w[v]=s[i];
			break;
		}else{
			d[++v]=a[i];
			w[v]=s[i];
			h+=a[i];
		}
	}
	h=0;
	for(int i=n;i>=1;i--){
		if(h+a[i]>=l){
			f[++b]=l-h;
			g[b]=s[i];
			break;
		}else{
			f[++b]=a[i];
			g[b]=s[i];
			h+=a[i];
		}
	}
	for(int i=1,j=1;i<=v&&j<=b;){
		if(w[i]==g[j]){
			if(f[j]>d[i]){
				f[j]=f[j]-d[i];
				i++;
			}else{
				if(d[i]>f[j]){
					d[i]=d[i]-f[j];
					j++;
				}else{
					i++,j++;
				}
			}
		}else{
			if(f[j]>d[i]){
				r=r+d[i];
				f[j]=f[j]-d[i];
				i++;
			}else{
				if(d[i]>f[j]){
				    r=r+f[j];
					d[i]=d[i]-f[j];
					j++;
				}else{
				    r=r+d[i];
					i++,j++;
				}
			}
		}
	}
	cout<<r;
	return 0;
}
