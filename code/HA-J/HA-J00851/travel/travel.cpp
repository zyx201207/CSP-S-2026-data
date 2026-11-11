#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
string ac,as,bc,bs;
cin>>ac>>as>>bc>>bs;
	int q=(as[0]-'A')*10+as[1]-'A';
	int w=(bs[0]-'A')*10+bs[1]-'A';
	int q1=max(q,w);
	int w1=min(q,w);
	

	
	int p1=4,p2=4;
	
	if(ac[0]==bc[0]&&ac[1]==bc[1]){cout<<1;
	}else{cout<<"0000";fclose(stdin);fclose(stdout);return 0;}

	if(q==w&&ac[0]==bc[0]&&ac[1]==bc[1]){cout<<1;
	}else{cout<<"000";fclose(stdin);fclose(stdout);return 0;}
	
	if(as[2]=='A'||as[2]=='B'||as[2]=='C')p1=1;
	else {p1=0;}
	if(bs[2]=='A'||bs[2]=='B'||bs[2]=='C')p2=1;
	else {p2=0;}
	if(q==w&&p1==p2&&ac[0]==bc[0]&&ac[1]==bc[1]){cout<<1;}
	else{cout<<"00";fclose(stdin);fclose(stdout);return 0;}
	

	
	if(q1-w1+max(as[2],bs[2])-min(as[2],bs[2])<=1&&ac[0]==bc[0]&&ac[1]==bc[1]&&!(as[2]=='D'&&bs[2]=='C')&&!(bs[2]=='D'&&as[2]=='C'))cout<<1;
	else {cout<<0;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
