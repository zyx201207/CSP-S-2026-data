#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int r1,x1,b=0;
	string r2,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		}
	else{
		cout<<0<<0<<0<<0;
		return 0;
		}
	for(int i=0;i<2;i++){
		if(r2[i]==x2[i]){
			b=1;
			}
			else{
				b=0;
				}
		}
		if(b==1){
			cout<<1;
			}
		else{
			cout<<1<<0<<0<<0;
			return 0;
			}
		if(r2[2]=='A'&& x2[2]=='B')cout<<1<<' ';
		else if(r2[2]=='A'&& x2[2]=='C')cout<<1;
		else if(r2[2]=='B'&& x2[2]=='C')cout<<1;
		else if(r2[2]=='B'&& x2[2]=='A')cout<<1;
		else if(r2[2]=='C'&& x2[2]=='B')cout<<1;
		else if(r2[2]=='C'&& x2[2]=='A')cout<<1;
		else if(r2[2]=='D'&& x2[2]=='F')cout<<1;
		else if(r2[2]=='F'&& x2[2]=='D')cout<<1;
		else{
			cout<<0;
			}
			
		if(r2[2]=='A'&&x2[2]=='B')cout<<1;
		else if(r2[2]=='B'&&x2[2]=='A')cout<<1;
		else if(r2[2]=='B'&&x2[2]=='C')cout<<1;
		else if(r2[2]=='C'&&x2[2]=='B')cout<<1;
		else if(r2[2]=='D'&&x2[2]=='F')cout<<1;
		else if(r2[2]=='F'&&x2[2]=='D')cout<<1;
		else{
			cout<<0;
			}
		
			
	return 0;
	}

