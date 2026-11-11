#include<bits/stdc++.h>
using namespace std;
int cn1,sn1,cn2,sn2;
string c1,s1,c2,s2,ss1,ss2;
char a1,a2;
bool b[10];
bool near(){
	if(a1<='C' && a2<='C'){
		if(abs(a1-a2)==1) return true;
		else return false;
	}else{
		if((a1=='D' && a2=='F')||(a1=='F' && a2=='D')){
			return true;
		}else return false;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cn1=stoi(c1);
	cn2=stoi(c2);
	if(cn1!=cn2) b[1]=false,b[2]=false,b[3]=false,b[4]=false;
	else{	
		ss1=s1.substr(0,2);
		ss2=s2.substr(0,2);
		a1=s1[2],a2=s2[2];
		sn1=stoi(ss1);
		sn2=stoi(ss2);
		if(sn1!=sn2) b[1]=true,b[2]=false,b[3]=false,b[4]=false;
		else{
			if(!((a1<='C' && a2<='C')||(a1>='D' && a2>='D'))){
				b[1]=true,b[2]=true,b[3]=false,b[4]=false;
			}else{
				if(!near()) b[1]=true,b[2]=true,b[3]=true,b[4]=false;
				else b[1]=true,b[2]=true,b[3]=true,b[4]=true;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<((b[i])?1:0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
