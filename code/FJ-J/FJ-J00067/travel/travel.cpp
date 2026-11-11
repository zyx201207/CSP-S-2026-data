//luogu_UID:2051996
//武道，当一往无前！
 #include<bits/stdc++.h>
using namespace std;
int cr,cx,spr,spx;
char sr[3],sx[3],ssr,ssx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr;for(int i=0;i<=2;i++)cin>>sr[i];	
	spr=(int)((sr[0]-'0')*10+(sr[1]-'0')),ssr=sr[2];
	cin>>cx;for(int i=0;i<=2;i++)cin>>sx[i];	
	spx=(int)((sx[0]-'0')*10+(sx[1]-'0')),ssx=sx[2];
	
	if(cr==cx){
		cout<<1;
		if(spr==spx){
			cout<<1;
			if(ssr=='A')
			{
				if(ssx=='B'){cout<<"11";return 0;}
				if(ssx=='C'){cout<<"10";return 0;}
				if(ssx=='D'){cout<<"00";return 0;}
				if(ssx=='F'){cout<<"00";return 0;}
			}
			if(ssr=='B')
			{
				if(ssx=='A'){cout<<"11";return 0;}
				if(ssx=='C'){cout<<"10";return 0;}
				if(ssx=='D'){cout<<"00";return 0;}
				if(ssx=='F'){cout<<"00";return 0;}
			}
			if(ssr=='C')
			{
				if(ssx=='B'){cout<<"11";return 0;}
				if(ssx=='A'){cout<<"10";return 0;}
				if(ssx=='D'){cout<<"00";return 0;}
				if(ssx=='F'){cout<<"00";return 0;}
			}
			if(ssr=='D')
			{
				if(ssx=='A'){cout<<"00";return 0;}
				if(ssx=='B'){cout<<"00";return 0;}
				if(ssx=='C'){cout<<"00";return 0;}
				if(ssx=='F'){cout<<"11";return 0;}
			}
			if(ssr=='F')
			{
				if(ssx=='A'){cout<<"00";return 0;}
				if(ssx=='B'){cout<<"00";return 0;}
				if(ssx=='C'){cout<<"00";return 0;}
				if(ssx=='D'){cout<<"11";return 0;}
			}
		}
		else{cout<<"000";return 0;}
	}	
	else{cout<<"0000";return 0;}
	
	return 0;
}

