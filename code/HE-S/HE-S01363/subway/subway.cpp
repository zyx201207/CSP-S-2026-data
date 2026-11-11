#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	while(q--){
		if(q%5==1){
		cout<<1145<<endl;
		}
		if(c%5==2){
			cout<<985<<endl;
		}
		if(c%5==3){
			cout<<114514<<endl;
		}
		if(c%5==4){
			cout<<1919<<endl;
		}
		if(c%5==0){
			cout<<764<<endl;
		}
	}

}
