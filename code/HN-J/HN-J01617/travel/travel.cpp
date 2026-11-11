#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travl.out","w",stdout);
	string b,d;
	int a,c;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b.size()==d.size()){
			int i;
			for(i=0;i<b.size()-1;i++){
				if(b[i]!=d[i]){
					cout<<"000";
					return 0;
				}
			}
			cout<<"1";
			if(b[i]>='A'&&b[i]<='C'&&d[i]>='A'&&d[i]<='C'){
				cout<<"1";
				if(b[i]=='B'||d[i]=='B'){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}	
			}else if(b[i]=='D'&&d[i]=='F'){
				cout<<"11";
				return 0;
			}else if(d[i]=='F'&&b[i]=='D'){
				cout<<"11";
				return 0;
			}
			cout<<"00";
			return 0;
		}
	}
	cout<<"0000";
	return 0;
}
