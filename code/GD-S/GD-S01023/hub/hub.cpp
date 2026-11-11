#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int c,t,n,k,u,v,a[N],ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		n/=2;
		k/=2;
		int l=1,r=k;
		while(r<n){
			ans=max(ans,max(l-1,n-r));
			l++,r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
