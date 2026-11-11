#include<bits/stdc++.h>
using namespace std;
int x1,y1;
string y2,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){
		cout<<1;
		x1=(x2[0]-'0')*10+(x2[1]-'0');
		y1=(y2[0]-'0')*10+(y2[1]-'0');
		if(x1==y1){
			cout<<1;
			if((x2[2]<='C'&&y2[2]<='C')||(x2[2]>='D'&&y2[2]>='D')){
				cout<<1;
				if(abs(x2[2]-y2[2])==1){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
