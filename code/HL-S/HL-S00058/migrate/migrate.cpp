#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long x[N];
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int id=read(),t=read();
	while(t--){
		int n=read();
		long long d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(id==11||id==12){
			int len=d/(x[2]-x[1]);
			long long sum=1ll*n*(n+1)/2;
			for(int i=1;i<=len;i++){
				sum-=(n-i+1);
			}
			for(int i=len;i+1<=n;i+=len){
				sum-=(n-i);
			}
			printf("%lld\n",sum);
			continue;
		}
//		if(n<=10){
			long long ans=0;
			for(int l=1;l<n;l++){
				for(int r=l+1;r<=n;r++){
					int M=1<<(r-l-1),mi=0x3f3f3f3f,cnt=0;
					for(int i=0;i<M;i++){
						bitset<20> bs(i);
						int f=1;
						int pos=l;
						for(int j=0;j<r-l-1;j++){
							if(bs[j]==1){
								if(abs(x[l+j+1]-x[pos])>d){
									f=0;
									break;
								}
								pos=l+j+1;
							}
						}
						if(abs(x[r]-x[pos])>d) f=0;
						if(f){
							if(bs.count()<mi){
								mi=bs.count();
								cnt=1;
							}
							else if(bs.count()==mi) cnt++;
						}
					}
					if(cnt==2) ans++;
				}
			}
			printf("%lld\n",ans);
//			continue;
//		}
	}
	return 0;
}