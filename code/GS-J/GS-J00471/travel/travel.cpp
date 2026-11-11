#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a, b, c, d;
	int o=0, m=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		o=1;
	}else{
		cout<<0; 
	}
	if(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
		if(o==1){
		cout<<1;
		}
		}else{
			cout<<0;
	m=1;
	}
	if(m!=0){
		if(b[2]==d[2]&&b[0]*10+b[1]+1==d[0]*10+d[1]){
			cout<<1;
		}
		 else if(b[2]==d[2]&&b[0]*10+b[1]-1==d[0]*10+d[1]){
			cout<<1;
		}
		 else if(b[2]+1==d[2]&&b[0]*10+b[1]==d[0]*10+d[1]){
			cout<<1;
		}
		 else if(b[2]-1==d[2]&&b[0]*10+b[1]==d[0]*10+d[1]){
			cout<<1;
			
		}else{
			cout<<0;
			
		}
		
	}else{
		cout<<0;
	}
	
	
	
	
	
	return 0;
}
