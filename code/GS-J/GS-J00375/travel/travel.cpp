#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	for(int i=1;i<=18;i++){
		for(int j=1;j<=6;j++){
		if(i==1||i==17){
			break;}
		if(c1==s1){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
		if(j==4){
			break;
		}
		if(j-1>0){
			cout<<"0"<<endl;
		}
	}
}	
	return 0;
}
