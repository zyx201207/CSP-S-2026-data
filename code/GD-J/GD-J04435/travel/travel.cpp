#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	char c,d,e,f,g,c2,d2,e2,f2,g2;
	cin>>c>>d>>e>>f>>g>>c2>>d2>>e2>>f2>>g2;
	if(c==c2&&d==d2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(e==e2&&f==f2){
		cout<<1;
		if((g=='A'||g=='B'||g=='C')&&(g2=='A'||g2=='B'||g2=='C')){
			cout<<1;
			if(g=='B'||g2=='B'){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}else if((g=='F'||g=='D')&&(g2=='F'||g2=='D')){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	
} 
