#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a,b,c,d,nb,nd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	nb=b.substr(0,2);
	nd=d.substr(0,2);
	if(a==c){
		cout<<1;
		if(nb==nd){
			cout<<1;
			if(((b[2]=='d'||b[2]=='f')&&(d[2]=='d'||d[2]=='f'))||((b[2]=='a'||b[2]=='b'||b[2]=='c')&&(d[2]=='a'||d[2]=='b'||d[2]=='c'))){
				cout<<1;
				if(b[2]=='d'||b[2]=='f'||b[2]=='b'||d[2]=='b'){
					cout<<1;
				}else{
					cout<<0;
				}		
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
