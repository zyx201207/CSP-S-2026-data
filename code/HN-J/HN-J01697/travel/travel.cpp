#include<bits/stdc++.h>
using namespace std;

string c_1,c_2,s_1,s_2;
int x=0,y=0;
int a=0,b=0,c=0,d=0,f=0;
void solve(char s){
	if(s>='A' and s<='C') x++;
	if(s=='D' or s=='F') y++;
	return ;
}
void solve_2(char s){
	if(s=='A') a++;
	if(s=='B') b++;
	if(s=='C') c++;
	if(s=='D') d++;
	if(s=='F') f++;
	return ;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<"1";
		if((s_1[0]-'0')*10+(s_1[1]-'0')==(s_2[0]-'0')*10+(s_2[1]-'0')){
		cout<<"1"; 
		solve(s_1[2]);
	    solve(s_2[2]);
	if(x==2 or y==2) cout<<"1";
	else cout<<"0";
	if(x==2){
		solve_2(s_1[2]);
		solve_2(s_2[2]);
		if(a==1 and b==1) cout<<"1";
		else if(b==1 and c==1) cout<<"1";
		else cout<<"0";
	}
	else if(y==2) cout<<"1";
	else cout<<"0"; 
	} 
	else{
		cout<<"000";
	} 
	} 
	else cout<<"0000"; 
	
	return 0;
} 
