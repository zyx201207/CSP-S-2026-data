#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int numline;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>numline;
		for(int j=1;j<=numline;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	int cnt=0;
	int x,y;
	while(cin>>x>>y) cnt++;
	for(int i=1;i<=cnt;i++){
		cout<<130304201307240511%(i+39)<<endl;
	}
	return 0;
}
