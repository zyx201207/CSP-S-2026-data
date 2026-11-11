#include <bits/stdc++.h>
/*
 tired 17qizhongkaoshi zhixielediyiti zuijinhaoleibuzhidaoganshenme
 kankan woxiedelieqidaima HBchu2 yinggaishi dao shu di 2 cilaiCSP-S
 gu ji 50-60fen ba ai leisiwole yitiantian de shuobuding jinnianjiuAFO
 zuihouganxieCCF
 I love CCF.``` 
 */
using namespace std;
const int MOD=2e5+5;
int c,n,m,d,q,w[MOD],k,a[mod][mod],t[mod][mod];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	return 0;
}
/*
 bu hui you ren neng kandongde 
 */
