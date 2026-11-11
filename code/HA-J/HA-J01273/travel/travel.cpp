#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else{
		//cout<<b[0]<<" "<<d[0]<<" "<<b[1]<<" "<<d[1];
		if(b[0]==d[0]&&b[1]==d[1]){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				//cout<<b[2]<<d[2];
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					if(d[2]=='B'||b[2]=='B') cout<<"1111";
					else cout<<"1110";
				}
				else cout<<"1100";
			}
			else if(b[2]=='D'||d[2]=='F'){
				if(b[2]=='D'||d[2]=='F') cout<<"1111";
			}
			/*if(a[2][3]==a[4][3]-1||a[2][3]-1==a[4][3]&&a[2][3]!='C',a[4][3]!='B'&&a[2][3]!='B',a[4][3]!='C'){
				
			}*/
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	return 0;
}
