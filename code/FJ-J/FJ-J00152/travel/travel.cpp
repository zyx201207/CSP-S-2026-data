#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	cout<<(c1==s1);
	string cc1,cc2,ss1,ss2;
	for(int i=0;i<=1;i++){
		cc1+=c2[i];
		ss1+=s2[i];
	}
	cc2=c2[2];
	ss2=s2[2];
	if((cc1==ss1)&&(c1==s1)){
		cout<<1;
		if("A"<=cc2&&cc2<="C"&&"A"<=ss2&&ss2<="C"||"D"<=cc2&&cc2<="F"&&"D"<=ss2&&ss2<="F"){
			cout<<1;
			if(cc2=="A"&&ss2=="B"||cc2=="B"&&ss2=="A"||cc2=="B"&&ss2=="C"||cc2=="C"&&ss2=="B")cout<<1;
			else if(cc2=="D"&&ss2=="F"||cc2=="D"&&ss2=="F")cout<<1;
			else cout<<0;
		}
		else cout<<"00";		
	}
	else {
		cout<<"000";
	}
	return 0;	
}
