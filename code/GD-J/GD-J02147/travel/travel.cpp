#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		if(c[0]==d[0] && c[1]==d[1]){
			cout<<1;
			int a1=c[2],b1=d[2];//65
			int c1=0,d1=0;
			if(a1>67)c1=1;
			if(b1>67)d1=1;
			if(c1==d1){
				cout<<1;
				if(abs(a1-b1)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else{cout<<"000";}
	}
	else{cout<<"0000";}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
