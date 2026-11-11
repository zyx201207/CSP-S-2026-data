#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int N=2e6+10;
int n,d,x[N],f1[N],f2[N];

int get(int a,int b){
	if(f1[f1[a]]>=b&&f2[f2[b]]<=a) return 1;
	return 0;
}

void solve(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d){
				f1[i]=j-1; break;
			}
		}
		if(f1[i]==0) f1[i]=n;
	}
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(x[i]-x[j]>d){
				f2[i]=j+1; break;
			}
		}
		if(f2[i]==0) f2[i]=1;
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<f2[i]<<" ";
	// cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=get(i,j);
		}
	}
	cout<<ans<<endl;
}


void solve11(){
	int ca=x[2]-x[1];
	// cout<<d/ca<<endl;
	int x=n-((d/ca)*2-1);
	if(x>=n-1||x<=0) cout<<0<<endl;
	else cout<<x<<endl;
	// cout<<n-((d/ca)*2-1)<<endl;
	// if(ca*2<=d&&ca*3>=d){
	// 	cout<<n/2<<endl;
	// }else cout<<0<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read(); d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(c==11||c==12)
			solve11();
		else solve();
	}	



	return 0;
}