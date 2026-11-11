#include<bits/stdc++.h> 
using namespace std;
int r1,x1;
char x2[8];
char r2[8];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if (r1==x1) {
		cout<<1;
		if (r2[0]==x2[0]&&r2[1]==x2[1]){
			cout<<1;
			if (r2[2]=='A'){
				if (x2[2]=='B')cout<<1;
				else if (x2[2]=='C')cout<<1;
				else cout<<0;
			}else if(r2[2]=='B'){
				if (x2[2]=='A')cout<<1;
				else if (x2[2]=='C')cout<<1;
				else cout<<0;
			}else if(r2[2]=='C'){
				if (x2[2]=='A')cout<<1;
				else if (x2[2]=='B')cout<<1;
				else cout<<0;
			}else if(r2[2]=='D'){
				if (x2[2]=='F')cout<<1;
			else cout<<0;
			}else if(r2[2]=='F'){
			if (x2[2]=='D')cout<<1;
			else cout<<0;
			}
			if (r2[2]=='A'){
				if (x2[2]=='B')cout<<1;
				else cout<<0;
			}else if(r2[2]=='B'){
				if (x2[2]=='A')cout<<1;
				else if (x2[2]=='C')cout<<1;
				else cout<<0;
			}else if(r2[2]=='C'){
				if (x2[2]=='B')cout<<1;
				else cout<<0;
			}else if(r2[2]=='D'){
				if (x2[2]=='F')cout<<1;
				else cout<<0;
			}else if(r2[2]=='F'){
				if (x2[2]=='D')cout<<1;
				else cout<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
