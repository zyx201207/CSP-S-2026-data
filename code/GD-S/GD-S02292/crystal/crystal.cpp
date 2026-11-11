#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;long long m;
ll a[500050];
int c[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=1;	
		if(a[i]!=i) fl=0;
	}
	sort(a+1,a+n+1);
	ll o=a[2]-a[1];int hl=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=o) hl=0;
	}
	long long u=m;
	if(fl==1){
		int kj=1;ll bb=m;
		while(bb>=kj&&kj<n){
			bb-=kj;
			kj++;
		}
		cout<<kj;
		return 0; 
	}
	if(hl==1){
		ll kwj=o;ll bwb=m;
		while(bwb>=kwj&&kwj<n*o){
			bwb-=kwj;
			kwj+=o;
		}
		cout<<kwj/o;
		return 0; 
	}
	int ans=1;
	for(int j=1;j<=n;j++){
		u=m;
		for(int i=j-1;i>=1;i--){
			int yop=a[j]-a[i];
			if(u>=yop){
			u-=yop;c[j]++;
			}
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,c[i]);
	}
	cout<<ans;return 0;
} 
