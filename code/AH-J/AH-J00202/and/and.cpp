#include<bits/stdc++.h>
using namespace std;
int n,m;
int a;
int low[200010][32];
int maxn;
int sh[200010];
inline void k(int x,int i){
	int k=0;
	while(x){
		low[i][k]=x&1;
		x>>=1;
		k++;
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a;
		k(a,i);
	}
	long long ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(sh[j]==maxn)cnt+=low[j][i];
		}
		if(cnt>=m){
			ans+=1ll<<i;
			for(int j=1;j<=n;j++){
				if(sh[j]==maxn&&low[j][i])sh[j]++;
			}
			maxn++;
		}
	}
	cout<<ans;
    return 0;
}
