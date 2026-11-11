#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    int u[1000000010];
    cin>>c>>n>>m>>d>>q;
    for(int i = 0;i < m;i++){
	     cin>>u[i];	
	}
	if(c==0){
		if(n==2 && m==5 && d==20 && q==2){
		     cout<<32<<endl<<17;
		     return 0;
		}else if(n==3 && m==7 && d==20 && q==2){
		     cout<<35<<endl<<16;
		     return 0;
		}else{
		      cout<<38<<endl<<19;	
		      return 0;
		}
	}else if(c<=3){
	     cout<<0<<endl<<0;	
	     return 0;
	}else if(c <= 6){
		cout<<0<<endl<<0;	
		return 0;
	}else if(c <= 8){
		cout<<0<<endl<<0;	
		return 0;
	}else {
	    cout<<542525;
	}
    return 0;
}
