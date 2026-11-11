#include<bits/stdc++.h>
using namespace std;
const int N=4e3+10;
int c,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
		}
		cout<<n/(k+1)<<'\n';
	}
	return 0;
}
