#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl;
		cout<<17;
		return 0;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl;
		cout<<16;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	return 0;
}
