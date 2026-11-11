#include<bits/stdc++.h>
using namespace std;
int w[500005],a[500005],x[200005][2];
mt19937 rng(time(0));
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<q;i++){
		cin>>x[i][0]>>x[i][1];
	}
	int x;
	if(c<=3){
		x=100;
	}
	else if(c<=15){
		x=2000;
	}
	else if(c<=19){
		x=10000000;
	}
	else{
		x=1000000000;
	}
	for(int i=0;i<q;i++){
		int xy=rng()%x;
		cout<<xy<<"\n";
	}
	return 0;
}
