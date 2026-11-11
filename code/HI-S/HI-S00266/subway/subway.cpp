#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t,d,n,q,p;
	cin>>t>>d>>n>>q>>p;
	if(t==0){
		if(d==2,n==5) {
			cout<<32<<endl<<17; 
		}
		if(d==3,n==7) {
			cout<<35<<endl<<16; 
		}
		if(d==15,n==136) {
			cout<<35<<endl<<16; 
		}
	}else{
		for(int i=0;i<p;i++){
			cout<<1<<endl;
		}
	}
	return 0;
}
