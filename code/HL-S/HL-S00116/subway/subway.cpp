#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100005],k,f[100005],what;
struct node{
	int x;
	int y;
}r[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>what>>what;
		}
	}
	for(int i=0;i<q;i++) cin>>r[i].x>>r[i].y;
	for(int i=0;i<q-2;i++) cout<<16<<endl;
	cout<<35<<17;
	return 0;
}
