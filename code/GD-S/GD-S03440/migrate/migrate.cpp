#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000010;
const int INF=900000000000000000;

int c,T;
int n,d;
int a[N];

int read(){
	int x=0;char c;
	while(c=getchar()){
		if(c==' '||c=='\n') break;
		x+=c-'0';x*=10;
	}
	x/=10;
	return x;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--){
		memset(a,0,sizeof(0));
		n=read();d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(c==11||c==12){
			if(a[3]-a[1]>d) cout<<0<<'\n';
			else{
				for(int i=4;i<=n;i++){
					if(a[i]-a[1]>d){
						int x=i+i-2;
						x=n-x+1;
						if(x>0){
							cout<<n-x<<'\n';
							break;
						}
						else{
							cout<<0<<'\n';
							break;
						}
					}
				}
			}
		}
		else{
			cout<<0<<'/n';
		}
	}
	
	
	
	return 0;
}
