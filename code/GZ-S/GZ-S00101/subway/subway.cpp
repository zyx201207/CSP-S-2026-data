//蒋木铮 贵阳第一中学 GZ-S00101 
#include<bits/stdc++.h>
using namespace std;
const int N=509;
int w[N],c,n,m,d,q,a[N],dist[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		dist[a][c]=b+d;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		int s=0;
		for(int i=l;i<=r-1;i++) s+=dist[i][i+1];
		cout<<s+w[l]+w[r]<<endl;
	}
	return 0;
}
