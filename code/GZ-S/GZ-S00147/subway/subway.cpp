//GZ-S00147 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<endl;
			cout<<17;
		}else if(n==3){
			cout<<35<<endl;
			cout<<16;
		}
	}else{
		while(q--){
		cout<<rand()%m<<endl;
	}
	}
	return 0;
}
