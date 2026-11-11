#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,b;
	string zw1,zw2;
	cin>>a>>zw1>>b>>zw2;
	if(a==b){
		cout<<1;
		long long psh1=0,psh2=0;
		for(int i=0;i<zw1.size()-1;i++){
			psh1=psh1*10+zw1[i]-48;
		}
		for(int i=0;i<zw2.size()-1;i++){
			psh2=psh2*10+zw2[i]-48;
		}
		if(psh1==psh2){
			cout<<1;
			if(zw1[zw1.size()-1]<='C' && zw2[zw2.size()-1]<='C' || zw1[zw1.size()-1]>'C' && zw2[zw2.size()-1]>'C'){
				cout<<1;
				if(abs(zw1[zw1.size()-1]-zw2[zw2.size()-1])==1 || zw1[zw1.size()-1]=='F' && zw2[zw2.size()-1]=='D' || zw1[zw1.size()-1]=='D' && zw1[zw1.size()-1]=='F'){
					cout<<1;
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
