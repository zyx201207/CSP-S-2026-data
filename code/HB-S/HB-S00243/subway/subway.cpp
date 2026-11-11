#include<bits/stdc++.h>
using namespace std;
int w[500005],n,m,c,d,q,x,y;
bool qu[500005][500];
int tim(int x,int y){
	int ans=0;
	ans+=w[x];
	ans+=w[y];
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int h,t;
			cin>>h>>t;
			qu[h][i]=1;//Line i has station h
		}
	}
	
	while(q){
		cin>>x>>y;
		cout<<tim(x,y)<<endl;
		q--;
	}
	return 0;
}
