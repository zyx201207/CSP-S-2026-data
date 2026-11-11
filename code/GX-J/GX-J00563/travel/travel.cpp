#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(a=="01"||c=="01"||a=="16"||c=="16") cout<<0;
		else cout<<1;
	}
	else cout<<0;
	for(int i=0;i<3;i++){
		if(i<2){
			if(b[i]==d[i]) cout<<1;
			else cout<<0;
		}
		else{
			if(b[i]==d[i]) cout<<0;
			else{
				if(b[i]=='D'&&d[i]=='F') cout<<1;
				else if(b[i]=='B'&&d[i]=='A') cout<<1;
				else if(b[i]=='F'&&d[i]=='D') cout<<1;
				else if(b[i]=='A'&&d[i]=='B') cout<<1;
				else if(b[i]=='C'&&d[i]=='B') cout<<1;
				else if(b[i]=='B'&&d[i]=='C') cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
}
