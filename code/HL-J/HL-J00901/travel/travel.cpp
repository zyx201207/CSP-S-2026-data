#include<bits/stdc++.h>
using namespace std;
char a[10],az[10],b[10],bz[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a[1]>>a[2];
    cin>>az[1]>>az[2]>>az[3];
    cin>>b[1]>>b[2];
    cin>>bz[1]>>bz[2]>>bz[3];
    if(a[1]==b[1]&&a[2]==b[2]){
    	cout<<1;
    	if(az[1]==bz[1]&&az[2]==bz[2]){
    		cout<<1;
    		int ba=0,bb=0;
    		if(az[3]>='A'&&az[3]<='C'){
    			ba=1;
			}
			else {
				ba=2;
			}
			if(bz[3]>='A'&&bz[3]<='C'){
    			bb=1;
			}
			else {
				bb=2;
			}
			if(ba==bb&&ba==1){
				cout<<1;
				if(az[3]=='B'||bz[3]=='B'){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(ba==bb&&ba==2){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
    return 0;
}