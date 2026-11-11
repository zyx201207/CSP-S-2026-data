#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int c,t;
int n,m,maxn=0;
int a[N],b[N],f[N];
map<int,bool> mp2[N];
bitset<N> bt;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		bt=0;
		int maxn=0;
		for(int i=1;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			bt.set(a[i]);
			bt.set(b[i]);
			mp2[a[i]][b[i]]=true;
			mp2[b[i]][a[i]]=true;
		}
		for(int i=1;i<=n;i++) maxn+=mp2[i].size();
		int Se=bt.count();
		if(maxn/2>=Se-1) cout<<m-1<<endl;
		else cout<<m-3<<endl;
	}
	return 0;
}

