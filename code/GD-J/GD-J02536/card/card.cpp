#include<iostream>
#include<cstdio>
using namespace std;
//#define int long long
#define cerr if(0)clog
int ls[500500];
int jmp[500500];
int rt[300300];
int ans[300300];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ls[i];
		jmp[rt[ls[i]]]=i;
		rt[ls[i]]=i;
	}
	for(int i=n;i>=0;i--){
		jmp[i]=rt[ls[i]];
		if(rt[ls[i]]==0)
		rt[ls[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cerr.width(4);
		cerr<<ls[i];
	}cerr<<'\n';
	for(int i=1;i<=n;i++){
		cerr.width(4);
		cerr<<jmp[i];
	}cerr<<'\n';
	for(int l=n;l>=1;l--){
		for(int i=l;i<=n;i++){
			ans[ls[i]]++;
			if(jmp[i])i=jmp[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
