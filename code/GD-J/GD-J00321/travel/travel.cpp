#include<bits/stdc++.h>
using namespace std;
struct train{
	string h;
	string z;
};

train r,x;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	bool f=1;
	
	cin >> r.h >> r.z;
	cin >> x.h >> x.z;
	
	for(int i=0;i<=1;i++){
		if(r.h[i] != x.h[i]){
			f=0;
		}
	}
	
	if(!f){
		cout << "0000";
		return 0;
	}
	cout<< "1";
	if(r.z[0]==x.z[0] && r.z[1]==x.z[1]){
		cout << "1";
		if(r.z[2]<='C' && r.z[2]>='A'){
			if(x.z[2]=='A' || x.z[2]=='B' || x.z[2]=='C'){
				cout<< "1";
				if(x.z[2]-1==r.z[2] || x.z[2]+1==r.z[2]){
					cout << "1";	
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<< "00";
			}
			
		}
		else if(r.z[2]<='E' && r.z[2]>='D'){
			if(x.z[2]=='E' || x.z[2]=='D'){
				cout<< "1";
				if(x.z[2]-1==r.z[2] || x.z[2]+1==r.z[2]){
					cout << "1";	
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout << "000";
	}
	
	return 0;
}

