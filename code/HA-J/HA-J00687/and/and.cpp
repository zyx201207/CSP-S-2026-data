#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,l,r,k,maxx;
bool b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	k=32;
	while(k--){
		int cnt=0;
//		cout<<k<<'\n';
		for(int i=1;i<=n;i++){
			if(b[i]){
				continue;
			}
			if((a[i]>>k)&1){
//				cout<<a[i]<<' ';
				cnt++;
			}
		} 
		if(cnt>=m){
			ans+=(1<<k);
			for(int i=1;i<=n;i++){
				if(b[i]){
					continue;
				}
				if(((a[i]>>k)&1)==0){
//					cout<<i;
					b[i]=1;
				}
			} 
		}
//		cout<<'\n';
	}
	cout<<ans;
	return 0;
}
