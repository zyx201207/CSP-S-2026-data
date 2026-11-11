#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string ints1,ints2,j,l;
int xr,xx;
int sh1(string r,string x){
	if((r=="A"&&(x=="B"||x=="C"))||(r=="B"&&(x=="A"||x=="C"))||(r=="C"&&(x=="B"||x=="A"))||(r=="D"&&x=="F")||(r=="F"&&x=="D")){int d=1;return d;}
	else if((x=="A"&&(r=="B"||r=="C"))||(x=="B"&&(r=="A"||r=="C"))||(x=="C"&&(r=="B"||r=="A"))||(r=="D"&&x=="F")||(r=="F"&&x=="D")){int d=1;return d;}
	else{int d=0;return d;}
}
int sh2(string r,string x){
	if((r=="A"&&x=="B")||(r=="B"&&(x=="A"||x=="C"))||(r=="C"&&x=="B")||(r=="D"&&x=="F")||(r=="F"&&x=="D")){int d=1;return d;}
	else if((x=="A"&&r=="B")||(x=="B"&&(r=="A"||r=="C"))||(x=="C"&&r=="B")||(r=="D"&&x=="F")||(r=="F"&&x=="D")){int d=1;return d;}
	else{int d=0;return d;}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{cout<<"0000";return 0;}
	for(int i=0;i<2;i++){
		ints1+=s1[i];
		ints2+=s2[i];
	}
	if(ints1==ints2)cout<<"1";
	else{cout<<"000";return 0;}
	j+=s1[2];
	l+=s2[2];
	int fl=sh1(j,l);
	if(fl==1)cout<<"1";
	else{cout<<"00";return 0;}
	fl=sh2(j,l);
	if(fl==1)cout<<"1";
	else{cout<<"0";}
	return 0;
} 
