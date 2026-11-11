#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+10;
const int inf=0x3f3f3f3f;
string rc,xc,rz,xz;
int rp,xp;
char rl,xl;
map<char,int> sit;
void init(){
	sit['A']=1;
	sit['B']=1;
	sit['C']=1;
	sit['D']=2;
	sit['F']=2;	 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	init();
	cin>>rc>>rz>>xc>>xz;
	for(int i=0;i<3;i++){
		if(isalpha(rz[i]))  rl=rz[i];
		if(isalpha(xz[i]))  xl=xz[i];
		if(isdigit(rz[i])){
			rp*=10;
			rp+=rz[i]-'0';
		}
		if(isdigit(xz[i])){
			xp*=10;
			xp+=xz[i]-'0';
		}
	}
	if(rc==xc){
		cout<<"1";
		if(rp==xp){
			cout<<"1";
			if(sit[rl]==sit[xl]){
				cout<<"1";
				if(abs(xl-rl)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		} 
	}else  cout<<"0000";
	return 0;
}

