#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0;
	int w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-w;
		ch=getchar();
	}
	s=ch-'0';
	while((ch=getchar())>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
	}
	return s*w;
}
const int N=2e6+3,M=5e5+3;
long long c,t,n,d,x[N],ca,p,cnt,f[N],sur,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();ans=cnt=0;
		for(int i=1;i<=n;i++){
			x[i]=read();
			f[i]=x[i]-x[i-1];
		}
		p=0;
		ca=x[2]-x[1];
		for(int i=3;i<=n;i++){
			if(ca!=x[i]-x[i-1]){
				p=1;
				break;
			}
		}
		if(!p){
			if(d<2*ca){
				cout<<0<<'\n';
			}else{
				if(ca*2<=d&&d<ca*3){
					cout<<(n-2)*(n-3)/2-(n-4)<<'\n';
				}else{
					cout<<(n-2)*(n-3)/2<<'\n';
				}
				
			}
			continue;
		}
		int nn=n-3;
		for(int i=1;i<=nn;i++){
			sur=0;
			if(f[i+1]>d||f[i+2]>d)continue;
			if(f[i+2]+f[i+1]<=d)sur++;
			for(int j=i+3;j<=n;j++){
				if(f[j]>d)break;
				if(f[j]+f[j-1]<=d)sur++;
				if(sur>=2){
					if(j==i+4){
						if(x[i+3]-x[i]>d||x[i+4]-x[i+1]>d){
							continue;
						}else{
							ans+=n-j+1;
							break;
						}
					}else{
					ans+=n-j+1;
					break;
					}
					
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
