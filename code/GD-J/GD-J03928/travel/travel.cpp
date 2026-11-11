#include<bits/stdc++.h>
using namespace std;

string x,y,n,m;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>x>>y>>n>>m;
	if(x==n){
		cout<<"1";
		int a=(y[0]-'0')*10+(y[1]-'0');
		int b=(m[0]-'0')*10+(m[1]-'0');
		if(a==b){
			cout<<"1";
			int c=y[2]-'A';
			int d=m[2]-'A';
			if(c<3&&d<3||c>=3&&d>=3){
				cout<<"1";		
				if(abs(c-d)==1) cout<<"1";
				else cout<<"0";
			} 
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}

