#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    bool x,y=false;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
		cout<<1;
		x=true;
	}
    else cout<<0;
    if(s1[0]==s2[0] && s1[1]==s2[1]) {
		cout<<1;
		y=true;
	}
    else cout<<0;
    if(s1[2]=='A'){
		if(s2[2]=='B' || s2[2]=='C') {
			cout<<1;
			if(x==true && y==true && s2[2]=='B') {
				cout<<1;
				return 0;
			}
		}
		else{
            cout<<00;
            return 0;
		}
	}
    else if(s1[2]=='B'){
		if(s2[2]=='A' || s2[2]=='C'){
			cout<<1;
			if(x==true && y==true) {
				cout<<1;
				return 0;
			}
			else{
                cout<<0;
                return 0;
			}
		}
        else{
            cout<<00;
            return 0;
        }
	}
    else if(s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B') {
			cout<<1;
			if(x==true && y==true && s2[2]=='B') {
				cout<<1;
				return 0;
            }
            else{
                cout<<0;
                return 0;
            }
		}
        else if(s2[2]=='D'){
            cout<<0<<0;
            return 0;
        }
        else{
            cout<<00;
            return 0;
        }

	}
    else if(s1[2]=='D'){
		if(x==true && y==true && s2[2]=='F') {
			cout<<11;
			return 0;
		}
		else{
			cout<<00;
			return 0;
		}
	}
    else if(s1[2]=='F'){
		if(x==true && y==true && s2[2]=='D') {
			cout<<11;
			return 0;
		}
		else{
			cout<<00;
			return 0;
		}
	}
    return  0;
}
