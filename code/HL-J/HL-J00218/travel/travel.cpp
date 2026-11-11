#include <bits/stdc++.h>
using namespace std;

string c_r,c_x,s_r,s_x;
string ans;
string g1 = "ABC";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_r>>s_r>>c_x>>s_x;
	if (c_r == c_x) ans = ans+"1";
	else{
		ans = "0000";
		cout<<ans<<endl;
		return 0;
	} 
	
	string pr,px,sr,sx;
	pr = s_r.substr(0,2);
	px = s_x.substr(0,2);
	if (pr == px) ans = ans+"1";
	else{
		ans = ans+"000";
		cout<<ans<<endl;
		return 0;
	}
	sr = s_r.substr(2,1);
	sx = s_x.substr(2,1);
	int fr,fx;
	fr = g1.find(sr);
	fx = g1.find(sx);
	if (fr!=-1 && fx!=-1){
		ans = ans+"1";
		if (fr+1==fx || fx+1==fr) ans = ans+"1";
		else ans = ans+"0";
		cout<<ans<<endl;
	}else if(fr==-1 && fx==-1){
		ans = ans+"11";
		cout<<ans<<endl;
		return 0;
	}else{
		ans = ans+"00";
		cout<<ans<<endl;
		return 0;
	}
//	cout<<sr<<' '<<sx<<endl;
//	cout<<ans<<endl;
	return 0;
}