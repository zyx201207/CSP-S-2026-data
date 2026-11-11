#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d; 
	int a,c;
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else{
		cout<<1;
		if(b[0]+b[1]!=d[0]+d[1]){
			cout<<"000";
		}
		else{
			cout<<1;
			if(b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A'){
				cout<<"1";
				if(abs((int)(b[2]-d[2]))==1)cout<<"1";
				else{cout<<"0";
				}
				
			}
			
			else if(b[2]<='D'&&b[2]>='E'&&d[2]<='D'&&d[2]>='E')
			{
			cout<<"1";if(abs((int)(b[2]-d[2]))==1)cout<<"1";
				else{cout<<"0";
				}}
			else{cout<<"00";
			}
			
		}
		
		
		
		
		
		
	}
	
	
	return 0;
}
