//¿ÓºŒ‘∆ GZ-J00361 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first;
#define se second;
#define pb push_back;
const int N=2E5+10;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>x>>y;
    if(a==x){
    	cout<<"1";
    	if(b[0]==y[0]&&b[1]==y[1]){
    		cout<<"1";
    		if(!((b[2]>='D'&&y[2]<='C')||(b[2]<='C'&&y[2]>='D'))){
    			cout<<"1";
    			if(abs(b[2]-y[2])==1){
    				cout<<"1"<<endl;
				}
				else{
					cout<<"0"<<endl;
				}
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else{
			cout<<"000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
    return 0;
}
