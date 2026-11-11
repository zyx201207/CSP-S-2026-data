#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool F[676][676];
void init(){
	memset(F,0,sizeof F);
	F['A']['B']=1;
	F['A']['C']=1;
	F['B']['A']=1;
	F['B']['C']=1;
	F['C']['A']=1;
	F['C']['B']=1;
	F['D']['E']=1;
	F['E']['D']=1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	init();
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(F[(int)b[2]][(int)d[2]]){
				cout<<1;
				F['A']['C']=F['C']['A']=0;
				if(F[(int)b[2]][(int)d[2]]) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}
