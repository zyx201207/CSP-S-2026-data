#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	char a,b,c,d,e,f,g,h,i,j;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
	if(a==f&&b==g){
		cout<<"1";
		if(c==h&&d==i){
			cout<<"1";
			if(int(e)<=67&&int(j)<=67){
				cout<<"1";
				if(int(e)==65&&int(j)==67)
					cout<<"0";
				else
					cout<<"1";
			}
			else if((int(e)>=68&&int(j)>=68))
				cout<<"11";
			else
				cout<<"00";
		}
		else
			cout<<"000";
	} 
	else
		cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
	} 
