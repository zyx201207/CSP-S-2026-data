//GZ-S00246 贵阳市观山湖区第一高级中学 王思凯 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+10]={0};
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<q;i++){
		int w;cin>>w;
		int a[w]={0},t[w]={0};
		for(int j=0;j<w;j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=0;i<q;i++){
		int x,y;cin>>x>>y;
	} 
	return 0;
}
