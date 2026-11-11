#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[3],d[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	cin>>c[1]>>c[2]>>c[3];
	cin>>b;
	cin>>d[1]>>d[2]>>d[3];
	int e=c[3]-'A'+1,f=d[3]-'A'+1;
	if(a==b){
		
		cout<<"1";
		
		if(c[1]==d[1]&&c[2]==d[2]){
			
			cout<<"1";
			
			if((e<=3&&f<=3)||(e>3&&f>3)){
				
				cout<<"1";
				
				if(e-f==1||e-f==-1){
					cout<<"1";
				}
				else cout<<"0";
				return 0;
			}
			else cout<<"00";
			return 0;
		}
		else cout<<"000";
		return 0;
	}
	else{
		cout<<"0000";
	}
	return 0;
}
