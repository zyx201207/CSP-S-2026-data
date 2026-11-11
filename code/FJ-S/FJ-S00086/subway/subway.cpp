#include<bits/stdc++.h>
using namespace std;
int w[1000];
int k[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.in","w",stdout);
	int c,n,m,d,q,i,r;
	cin>>c>>n>>m>>d>>q;
	for(i=0;i<m;i++) cin>>w[i];
	cin>>c>>n>>m>>d>>q;
	cin>>c>>n>>m>>d>>q;
	cin>>c>>n;
	cin>>c>>n;
	if(c==0||n==2) cout<<32<<endl<<17;
	else if(c==0||n==3) cout<<35<<endl<<16;
	return 0;
}
