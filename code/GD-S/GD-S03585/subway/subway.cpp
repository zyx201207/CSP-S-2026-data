#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long wl[500010];
struct way{
	int z;long long w;
};
vector<way>wa[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>wl[i];
	}
	for(int i=0;i<n;i++){
		int k;int z,t;
		cin>>k;
		cin>>z>>t;
		wa[i].z=z;
	}
	for(int i=0;i<q;i++){
		if(c>=7&&c<=11){
			int qq,zz;cin>>qq>>zz;
			
		}
	}
	
}
