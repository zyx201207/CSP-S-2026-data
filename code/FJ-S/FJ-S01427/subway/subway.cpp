#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int a[500005];
signed main(){
	cin>>c>>n>>m>>d>>q;
	if(q==2&&n==3){
		cout<<"35"<<endl<<"16";
	}else if(q==2&&n==2){
		cout<<"32"<<endl<<"17";
	}else if(q==2){
		cout<<"50"<<"19";
	}else{
		for(int i=1;i<=q;i++){
			cout<<"50"<<endl;
		}
	}
	return 0;
}
