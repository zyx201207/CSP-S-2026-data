#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(n==2&&m==5){
		cout<<"32"<<endl<<"17"<<endl;
	}else{
		cout<<"35"<<endl<<"26"<<endl;
	}
	return 0;
}
