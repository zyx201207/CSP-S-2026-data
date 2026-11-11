#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f; 
}
long long mi(long a,long b){
	if(a<=b)return a;
	return b;
}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		long long dis[n+1][n+1];
		memset(dis,0,sizeof(dis));
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					if(dis[i][j]==0)
						dis[i][j]=abs(x[i]-x[j]);
					if(d>=dis[i][j]){
						continue;
					}
					else{
						if(dis[i][j]%d!=0){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
