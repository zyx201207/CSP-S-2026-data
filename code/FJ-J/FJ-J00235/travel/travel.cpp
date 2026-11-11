#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
bool fg[4];
int c[6]={1,1,1,2,3,2};
inline bool ck(char r,char x){
	if(r-'A'>x-'A') swap(r,x);
	if(x-r!=1 && x!='F') return false;
	if(x=='D') return false;
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> cr >> sr >> cx >> sx;
	fg[0]=false,fg[1]=false,fg[2]=false,fg[3]=false;
	if(cr==cx)
		fg[0]=true;
	if(sr[0]==sx[0] && sr[1]==sx[1] && fg[0]==true)
		fg[1]=true;
	if(c[sr[2]-'A']==c[sx[2]-'A'] && fg[1]==true)
		fg[2]=true;
	if(fg[2]==true && ck(sr[2],sx[2]))
		fg[3]=true;
	for(int i=0;i<=3;i++){
		if(fg[i]==true) cout << '1';
		else cout << '0';
	}
	return 0;
}
