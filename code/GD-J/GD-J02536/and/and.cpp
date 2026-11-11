#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//#define int long long
#define cerr if(0)clog
bool ls[200200][40];
bool pre[200200];
bool ans[40];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int b=0;t;b++,t/=2){
			ls[i][b]=(t%2);
		}
	}
	fill(pre,pre+n+10,1);
	
	for(int b=38;b>=0;b--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=(pre[i]&&ls[i][b]);
//			cerr<<pre[i];
		}
//		cerr<<'\n';
		if(cnt>=m){
			ans[b]=1;
			cerr<<" > choice "<<b<<'\n';
			for(int i=1;i<=n;i++){
				cerr<<pre[i];
			}cerr<<'\n';
			for(int i=1;i<=n;i++){
				pre[i]=ls[i][b]&&pre[i];
			}
		}
	}
	int ret=0;
	for(int i=38;i>=0;i--){
		ret*=2;
		ret+=(bool)ans[i];
	}
	cout<<ret;
	return 0;
}
