#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
const ll N=2e5+10;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1==x2){
		cout<<1;
		if(y1[0]==y2[0]&&y1[1]==y2[1]){
			cout<<1;
			if((y2[2]<='C'&&y1[2]<='C')||(y2[2]>='D'&&y1[2]>='D')){
				cout<<1;
				if(abs(y2[2]-y1[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	
	
	return 0;
}
