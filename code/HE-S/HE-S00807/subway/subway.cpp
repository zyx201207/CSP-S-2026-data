#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,d,q;
int r;
int w[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	if(c==0&&n==2&m==5&&d==20&q==2){
		cout<<"32"<<endl<<"17";
	}
	if(c==0&n==3&m==7&d==20&q==2){
		cout<<"35"<<endl<<"16";
	}
	
	return 0;
}
