#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,dtk[500010],nb; 
struct node{
	int k;
	int zd[500010],dtz[500010];
}zc[523];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>dtk[i];
	for(int i=1;i<=n;i++){
		 cin>>zc[i].k;
		 for(int j=1;j<=zc[i].k ;j++){
		 	 cin>>zc[i].dtz[j] >>zc[i].zd[j];
		 	 nb+=zc[i].zd[j];
		 } 
	}
	for(int i=1;i<=q;i++) {
		int ks,jw,ans=0;
		cin>>ks >>jw ;
		ans=dtk[ks]+dtk[jw]+nb;
		cout<<nb<<endl;
	}
	return 0;
} 
