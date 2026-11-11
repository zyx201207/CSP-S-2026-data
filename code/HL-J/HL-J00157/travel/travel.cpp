#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,sa,cb,sb;
    cin>>ca>>sa>>cb>>sb;
    if(ca==cb && ca != "01" && ca !="16"){
        cout<<1;
        if(sa[0]==sb[0] && sa[1]==sb[1]){
            cout<<1;
			if((sa[2] != 'D' && sb[2] != 'F') && (sa[2] != 'F' && sb[2] != 'D')){
				cout<<1;
				if(sa[2]-sb[2]==1 || sb[2]-sa[2]==1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
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
}
