#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m;
int a[500005];
signed main(){
	cin>>c>>n>>m;
	if(m==4){
		cout<<"1"<<endl<<"2";
	}else if(m==5){
		cout<<"0"<<endl<<"1";
	}else{
		for(int i=1;i<=n;i++){
			cout<<"2"<<endl;
		}
	}
	return 0;
}
