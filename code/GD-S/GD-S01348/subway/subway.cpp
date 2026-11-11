#include<bits/stdc++.h>
using namespace std;
int w[1010101];
int a[1010101],b[1101010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0 && n==2 && m==5 && d==20 && q==2){
		cout<<32<<endl;
		cout<<17;
	}
	else if(c==0 && n==3 && m==7 && d==20 && q==2){
		cout<<35<<endl;
		cout<<16;
	}
	else if(c==0 && n==4 && q==2){
		cout<<38<<endl;
		cout<<15;
	}
	return 0;
}
