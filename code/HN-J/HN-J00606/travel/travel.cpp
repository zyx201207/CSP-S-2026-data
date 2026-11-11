#include<bits/stdc++.h>
using namespace std;
int a,b;
string ahz,bhz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ahz>>b>>bhz;
	int ah=(ahz[0]-'0')*10+ahz[1]-'0',bh=(bhz[0]-'0')*10+bhz[1]-'0';
	string az="",bz="";
	az+=ahz[2];
	bz+=bhz[2];
//	cout<<a<<" "<<ah<<" "<<az<<endl;
//	cout<<b<<" "<<bh<<" "<<bz;
	if(a!=b){
		cout<<"0000";
	}else{
		cout<<"1";
		if(ah!=bh){
			cout<<"000";
		}else{
			cout<<"1";
			if(!((az=="A"&&(bz=="B"||bz=="C"))||(az=="B"&&(bz=="A"||bz=="C"))||(az=="C"&&(bz=="B"||bz=="A")))){
				if(az=="D"&&bz=="F"||az=="F"&&bz=="D"){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else{
				cout<<"1";
				if(az=="B"||bz=="B"){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
