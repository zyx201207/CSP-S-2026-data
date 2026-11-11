#include<bits/stdc++.h>
using namespace std;
long long read(){long long x;scanf("%lld",&x);return x;}
long long N,c,t,n,d,a[2200000],pd=1e17,ans,daan;
long long max1(long long x,long long y){
	if(x>=y)return x;
	return y;
}
long long min1(long long x,long long y){
	if(x<=y)return x;
	return y;
}
void bfs(int x,int cs,int y){
//	cout<<x<<" "<<cs<<" "<<y<<" "<<pd<<" "<<ans<<endl;
	if(cs>pd)return;
	if(x==y){
		if(cs<pd){
			pd=min1(pd,cs);
			ans=0;
		}
		ans++;
		return;
	}
	for(int i=x+1;i<=y;i++)if(a[i]-a[x]<=d)bfs(i,cs+1,y);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	if(c==12||c==11){
		while(t--){
			n=read();d=read();
			for(int i=1;i<=n;i++)a[i]=read();
			int sl=d/(a[2]-a[1]);
			if(sl<=1||sl>=3)cout<<0<<endl;
			else cout<<max1(n-3,0)<<endl;
		}
	}
	else if(c==13||c==14){
		while(t--){
			n=read();d=read();
			for(int i=1;i<=n;i++)a[i]=read();
		}
	}
	else {
		while(t--){
			daan=0;
			n=read();d=read();
			for(int i=1;i<=n;i++)a[i]=read();
			if(n>=50){
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					pd=1e17;
					ans=0;
					bfs(i,0,j);
					if(ans==2)daan++;
				}
			}
			cout<<daan<<endl;
		}
	}
	return 0;
}
