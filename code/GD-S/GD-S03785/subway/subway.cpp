#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],bg,ed,ans,x;
struct subway{
	int a;
	int t;
}b[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>b[i][j].a>>b[i][j].t ;
		}
	}
	for(int i=1;i<=q;i++){
		bool flag=0,o=1;
		cin>>bg>>ed;
		ans=w[bg]+w[ed];
		for(int j=1;j<=n;j++){
			if(flag){
				break;
			}
			for(int z=1;z<=x;z++){
				if(b[j][z].a==bg&&o){
					ans+=b[j][z].t;
					o=0;
				}
				if(b[j][z].a==ed&&flag){
					ans+=b[j][z].t;
					flag=1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
