#include<bits/stdc++.h>
#define int long long
using namespace std;
string ds,ds1,ds2,ds3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ds>>ds1>>ds2>>ds3;
	if(ds!=ds2){
		cout<<"0000\n";
	}
	else{
		cout<<"1";
		string dss,dss1;
		dss=ds1[0],dss1=ds3[0];
		dss+=ds1[1],dss1+=ds3[1];
		if(dss==dss1) cout<<"1";
		else{
			cout<<"000\n";
			return 0;
		}
		if(ds1[2]=='A'||ds1[2]=='B'||ds1[2]=='C'){
			if(ds3[2]=='D'||ds3[2]=='F'){
				cout<<"00\n";
				return 0;
			}
			else cout<<"1";
		}
		else{
			if(ds3[2]=='A'||ds3[2]=='B'||ds3[2]=='C'){
				cout<<"00\n";
				return 0;
			}
			else cout<<"1";
		}
		if(ds3[2]=='A'&&ds1[2]=='B'){
			cout<<"1\n";
		}
		else if(ds1[2]=='A'&&ds3[2]=='B'){
			cout<<"1\n";
		}
		else if(ds1[2]=='B'&&ds3[2]=='C'){
			cout<<"1\n";
		}
		else if(ds3[2]=='B'&&ds1[2]=='C'){
			cout<<"1\n";
		}
		else if(ds1[2]=='D'&&ds3[2]=='F'){
			cout<<"1\n";
		}
		else if(ds3[2]=='D'&&ds1[2]=='F'){
			cout<<"1\n";
		}
		else cout<<"0\n";
	}
	return 0;
}
