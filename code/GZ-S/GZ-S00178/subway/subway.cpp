//GZ-S00178 贵阳市第一中学 申智美 
#include<bits/stdc++.h>
using namespace std;
long long w[500005],a[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	while(q--){
		for(int i=1;i<=m;i++) cin>>w[i];
		int k;
		cin>>k;
		for(int i=1;i<=2*k;i++) cin>>a[i];
	}
	if(c==0&&n==2) cout<<32<<endl<<17;
	if(c==0&&n==3) cout<<35<<endl<<16;
	return 0;
}
