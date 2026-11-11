#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int i=0;
	if(a1==b1){
		cout<<"1";
		if(a2[0]==b2[0] && a2[1]==b2[1]){
			cout<<"1";	
			if(a2[2]-'0'<=67 && b2[2]-'0'<=67  || a2[2]-'0'>67 && b2[2]-'0'>67){
				cout<<"1";
				if(a2[2]-'0'+1==b2[2]-'0' && a2[2]!='C' || a2[2]-'0'-1==b2[2]-'0' && a2[2]!='D'){
					cout<<"1";
				}
				else{
					cout<<"0";
					i+=1;
				}
			}
			else{
				cout<<"0";
				i+=1;
			}
		}
		else{
			cout<<"0";
			i+=1;
		}
	}
	else{
		cout<<"0";
		i+=1;
	}
	for(int j=0;j<4-i;j++){
		cout<<"0";
	}
	cout<<"\n";
	return 0;
}




