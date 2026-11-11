#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string sx,sy;
	cin>>x;
	cin>>sx;
	cin>>y;
	cin>>sy;
	if(x==y){
		cout<<'1';
		if(sx[1]==sy[1]&&sx[0]==sy[0]){
			cout<<'1';
			if(sx[2]>='D'&&sy[2]>='D'){
				cout<<"11";	
			}
			else if(sx[2]<='C'&&sy[2]<='C'){
				cout<<'1';
				if(sx[2]+1==sy[2]||sx[2]-1==sy[2]){
					cout<<'1';
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
