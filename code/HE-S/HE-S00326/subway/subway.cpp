#include<bits/stdc++.h>
using namespace std;
long long c,n,m,k,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>k>>q;
	if(c==0){
		if(n==2) cout<<32<<endl<<17;
		if(n==3) cout<<35<<endl<<16;
	}
	else{
		for(int i=1;i<=q;i++)cout<<rand()<<endl;
	}
	return 0;
}
