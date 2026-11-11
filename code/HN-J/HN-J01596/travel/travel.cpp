#include<bits/stdc++.h>
using namespace std;
int z1,z2;
string p1,p2;
bool a;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>z1>>p1>>z2>>p2;
	while(z1==z2){
		if(p1==p2){
			a+="1";
		}else{
			a+="0";
		}
	}
	cout<<a;
	return 0;
}  
