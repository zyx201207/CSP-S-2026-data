#include <bits/stdc++.h>

using namespace std;

bool SameSide(char al,char bl){
	if((al<'D'&&bl<'D')||(al>'C'&&bl>'C'))
		return true;
	return false;
}

bool NextTo(char al,char bl){
	if(al<'D'&&bl<'D'){
		if(abs(al-bl)==1)
			return true;
		return false;
	}
	if(al>'C'&&bl>'C')
		return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int rc,xc;
    string rs,xs;
    cin>>rc>>rs>>xc>>xs;
    int rp=(rs[0]-'0')*10+(rs[1]-'0'),xp=(xs[0]-'0')*10+(xs[1]-'0');
    char rl=rs[2],xl=xs[2];
    if(rc!=xc){
    	cout<<"0000";
    	return 0;
	}
	else
		cout<<'1';
	if(rp!=xp){
		cout<<"000";
		return 0;
	}
	else
		cout<<'1';
	if(!SameSide(rl,xl)){
		cout<<"00";
		return 0; 
	}
	else
		cout<<'1';
	if(!NextTo(rl,xl))
		cout<<'0';
	else
		cout<<'1';
} 
