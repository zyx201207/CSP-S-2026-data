#include<bits/stdc++.h>
using namespace std;
int main(){
	//GZ-J00036,贵州省贵阳市南明区第一实验中学，罗圣杰 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f,g,h,i,j,k,l;
	cin>>a>>b>>c>>d;
	e=b[0];
	g=b[1];
	f=d[0];
	h=d[1];
	i=e+g;
	j=f+h;
	k=b[2];
	l=d[2];
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==c&&i==j){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==c&&i==j&&((k=="A"||k=="B"||k=="C")&&(l=="A"||l=="B"||l=="C"))||a==c&&i==j&&((k=="D"||k=="F")&&(l=="D"||l=="F"))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(a==c&&i==j&&((k=="A"&&l=="B")||(k=="B"&&l=="A")||(k=="B"&&l=="C")||(k=="C"&&l=="B")||(k=="D"&&l=="F")||(k=="F"&&l=="D"))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
} 
