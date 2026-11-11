#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){  //同一节车厢 
		cout<<1;
		if(b[0]==d[0] && b[1]==b[1]){  //同一排 
			cout<<1;
			if(((b[2]=='A' || b[2]=='B'||b[2]=='C') && ([2]=='A' || b[2]=='B'||b[2]=='C')) || ((b[2]=='D' || b[2]=='F') && (d[2]=='D' || d[2]=='F'))){ //过道同一边 
				if(b[2]=='A' && d[2]=='B' || b[2]=='B' && b[2]=='A' || b[2]=='C' && d[2]=='B' || b[2]=='B' && b[2]=='C' ){ //相邻 
					cout<<1;
				}else if(b[2]=='D' && d[2]=='F' || b[2]=='F' && b[2]=='D' ) {
					cout<<1
				}else{
					cout<<1110 
				} 
			}else{
				cout<<1100;
				return 0;
			}
		}else{
			cout<<1000;
			return 0;
		}
	}else{
		cout<<0000;
		return 0;
	}
	return 0;
}

