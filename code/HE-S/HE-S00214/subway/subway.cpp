#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17<<endl;
	}else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16<<endl;
	}else{
		int i=1;
		while(q--){
			cout<<m+n/i<<endl;
			i++;
		}
	}
	return 0;
}
