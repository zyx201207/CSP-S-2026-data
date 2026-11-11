#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+5;
const int inf=INT_MAX;
const ll lnf=LLONG_MAX;
using namespace std;

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]+b[1]==d[0]+d[1]){
			cout<<"1";
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
				cout<<"1";
				if(abs(b[2]-d[2])==1){
					cout<<"1"; 
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
