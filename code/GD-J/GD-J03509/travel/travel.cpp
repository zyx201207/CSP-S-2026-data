#include<bits/stdc++.h>
using namespace std;
int n,cr[10],cx[10],pds=0,dsg;
string a,b,c,d; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		}else{
			cout<<"0000";
			return 0;
		}
		for(int i=0;i<=1;i++){
			if(b[i]==d[i]){
				pds++;
			}
		}
		if(pds==2){
			cout<<1;
		}else{
			cout<<"000";
			return 0;
		}
		int xrg=b[2],xxg=d[2];//ÅÐ¶Ï3,ÐèÈ¡2;
		 if(xrg=='D'&&xxg=='E'||xrg=='E'&&xxg=='D'||xrg=='A'&&xxg=='B'||xrg=='A'&&xxg=='C'||xrg=='B'&&xxg=='C'||xrg=='B'&&xxg=='A'||xrg=='C'&&xxg=='A'||xrg=='C'&&xxg=='B'){
		 	cout<<1;
		 }else{
		 	cout<<"00";
		 	return 0;
		 }
		 if(xrg=='D'||xrg=='E'||xrg=='B'||xxg=='B'){
		 	cout<<1;
		 }else{
		 	cout<<0;
		 }
	return 0;
} 
