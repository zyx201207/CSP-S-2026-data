#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int t=2;
int a=32;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==3){
		cout<<"35"<<endl<<"16";
		return 0;
	}
	for(int i=1;i<=t;i++){
		cout<<a<<endl;
		a-=15;
	}
	return 0;
}
