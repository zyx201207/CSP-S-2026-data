#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string w1="",w2="",a1="",a2="";
	w1+=s1[0],w1+=s1[1];
	w2+=s2[0],w2+=s2[1];
	a1+=s1[2],a2+=s2[2];
	if(w1==w2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((a1=="A"||a1=="B"||a1=="C")&&(a2=="A"||a2=="B"||a2=="C")){
		cout<<"1";
	}else if((a1=="F"||a1=="D")&&(a2=="F"||a2=="D")){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(a1=="A"&&a2=="B"){
		cout<<"1";
	}else if(a1=="B"&&(a2=="A"||a2=="C")){
		cout<<"1";
	}else if(a1=="C"&&a2=="B"){
		cout<<"1";
	}else if(a1=="F"&&a2=="D"){
		cout<<"1";
	}else if(a1=="D"&&a2=="F"){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
