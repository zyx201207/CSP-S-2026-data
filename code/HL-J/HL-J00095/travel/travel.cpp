#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int z[9];
	if(a==c){
		z[1]=1;
		if(b[0]==d[0]&&b[1]==d[1])	
		{
			z[2]=1;
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')||(b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
				z[3]=1;
				if(b[2]+1==d[2]||b[2]-1==d[2]){
					z[4]=1;
				}
				else{
					cout<<"1110";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	cout<<z[1]<<z[2]<<z[3]<<z[4];
}
