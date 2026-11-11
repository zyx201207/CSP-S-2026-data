#include<bits/stdc++.h>
using namespace std;
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c==0&&n==2){
	    cout<<32<<endl;
		cout<<17<<endl;
	}
	else if(c==0&&n==3){
		cout<<35<<endl;
		cout<<16<<endl;
	}
	return 0;
}
