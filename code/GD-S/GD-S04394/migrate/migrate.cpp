#include<bits/stdc++.h>
using namespace std;
long long pos[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
//	if(c==11||c==12){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
				memset(pos,0,sizeof(pos));
				long long g,h;
				cin>>g>>h;
				for(int i=0;i<g;i++){
					cin>>pos[i];
				}
				long long ans=0;
				for(int i=2;i<=g-1;i++){
					if((pos[1]-pos[0])*i<=h&&(pos[1]-pos[0])*(i+1)>=h){
						ans+=g-i-1;
					}
				}
				cout<<ans<<'\n';
			
		}
//	}
	return 0;
}
