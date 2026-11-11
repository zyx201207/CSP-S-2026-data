#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int d1,d2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		d1=d1*10+(s1[i]-'0');
		d2=d2*10+(s2[i]-'0');
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(d1!=d2){
		cout<<"1000";
		return 0;
	}
	int a1=s1[2]-'A',a2=s2[2]-'A';
	if(a1<3){
		if(a2<3){
			if(abs(a2-a1)==1) cout<<"1111";
			else cout<<"1110";
		}else cout<<"1100";
	}
	else{
		if(a2>=3) cout<<"1111";
		else cout<<"1100";
	} 
	return 0;
} 
