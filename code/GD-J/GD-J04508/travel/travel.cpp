#include<bits/stdc++.h>
using namespace std;

int ra,rb,rc,xa,xb,xc;
string rs,xs;
bool l[4];

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>ra>>rs>>xa>>xs;
	rb = (rs[0]-'0')*10 + (rs[1]-'0');
	xb = (xs[0]-'0')*10 + (xs[1]-'0');
	rc = rs[2];
	xc = xs[2];
	if(rc == 'F')rc--;
	if(xc == 'F')xc--;
	
	if(ra == xa){
		l[0] = 1;
		
		if(rb == xb){
			l[1] = 1;
			
			if((rc<='C' && xc <= 'C' )|| (rc>='D' && xc>='D')){
				l[2] = 1;
				
				if(rc-xc == 1 || rc-xc == -1){
					l[3] = 1;
				}
				
			}else{
				l[2] = 0;
			}
			
		}else{
			l[1] = 0;
		}
		
	}else{
		l[0] = 0;
	}

	for(const auto i:l)cout<<i;
	cout<<"\n";
			
	
	
	
	
	
	return 0;
	
}
