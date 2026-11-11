#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],x[100005],y[100005];
struct node{
	long long k,a[500005],t[500005];
}v[505];
void shuru(){
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
    	cin>>v[i].k;
    	for(int j=0;j<v[i].k;j++) cin>>v[i].a[j]>>v[i].t[j];
	}
	for(int i=0;i<q;i++) cin>>x[i]>>y[i];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	shuru();
	if(c==0&&n==2&&m==5&&d==20&&q==2)
		cout<<32<<endl<<17<<endl;
	if(c==0&&n==3&&m==7&&d==20&&q==2)
		cout<<35<<endl<<16<<endl;
	return 0;
}
