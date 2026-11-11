#include<iostream>
#include<cstdio>
using namespace std;
int hanshu(string s){
	int l;
	l=(int)(s[0]-'0')*10;
	l+=(int)(s[1]-'0');
	return l;
}
int zimu(char cr,char ch){
	int c1=0,c2=0;
	c1=(int)(cr-'A'+1);
	c2=(int)(ch-'A'+1);
	if(c1!=c2&&(c1-c2==1||c1-c2==-1)) return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string zwR,zwX;
	int cxR,cxX,Rw,Xw;
	cin>>cxR>>zwR>>cxX>>zwX;
	if(cxR==cxX){
		cout<<"1";
		if(zwR[0]==zwX[0]&&zwR[1]==zwX[1]){
		    cout<<"1";
		    if(zwR[2]=='A'||zwR[2]=='B'||zwR[2]=='C') Rw=1;
		    else Rw=0;
		    if(zwX[2]=='A'||zwX[2]=='B'||zwX[2]=='C') Xw=1;
		    else Xw=0;
		    if(Rw==Xw){
			    cout<<"1";
		    }
		    else cout<<"00";
	    }
	    else cout<<"00";
	}
	else cout<<"000";
	if(Rw==Xw){
		int hR=hanshu(zwR),hX=hanshu(zwX);
	    if(zwR[2]==zwX[2]&&(hR-1==hX||hR+1==hX)) cout<<"1";
	    else if(hR==hX&&zimu(zwR[2],zwX[2])==1) cout<<"1";
	    else cout<<"0";
	}
	return 0;
}
