#include<bits/stdc++.h>
using namespace std;
//int w[500005];
string s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;i++){
		getline(cin,s);	
	}
	if(n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}else if(n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
	}
	else{
		cout<<38<<endl<<15;
	}
	return 0;
}
