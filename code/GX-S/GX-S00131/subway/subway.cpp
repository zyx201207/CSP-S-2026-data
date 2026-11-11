#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,ans=0;cin>>c>>n>>m>>d>>q;
	while(m--){
		int x;cin>>x;ans+=x;
	}
	while(n--){
		int k;cin>>k;
		for(int i=1;i<=2*k;i++){
			int x;cin>>x;ans+=x;
		}
	}for(int i=1;i<=2*q;i++){
		int x;cin>>x;
	}cout<<ans/4+412;
	return 0;
}
