#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	for(int i=0;i<3;i++){
		if((b[0]==d[0] && b[1]==d[1]) && (int(b[2])!=int(d[2]))){
			cout<<1;
			break;
		}else{
			cout<<0;
			break;
		}
	}
	for(int i=0;i<3;i++){
		if((b[0]==d[0] && b[1]==d[1]) && ((b[2]=='D' && b[2]=='F') || (b[2]=='F' && b[2]=='D') || (b[2]=='A' && d[2]=='B') || (b[2]=='A' && d[2]=='C') || (b[2]=='B' && d[2]=='A') || (b[2]=='B' && d[2]=='C') || (b[2]=='C' && d[2]=='A') || (b[2]=='C' && d[2]=='B'))){
			cout<<1;
			break;
		}else{
			cout<<0;
			break;
		}
	}
	for(int i=0;i<3;i++){
		int k=int(b[2]);
		if((b[0]==d[0] && b[1]==d[1]) && ((k+1==int(d[2])) || (k-1==int(d[2])))){
			if((b[2]=='C' && d[2]=='D') || (b[2]=='D' && d[2]=='C')){
				cout<<0;
				break;
			}else{
				cout<<1;
				break;
			}
		}else{
			cout<<0;
			break;
		}
	}
	return 0;
}
