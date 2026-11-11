#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int sa,sb;char a,b;
string ifside(char q,char w){
	if(q=='A'){
		if(w=='B') return "11";
		if(w=='C') return "10";
		return "00";}if(q=='B'){
		if(w=='A') return "11";
		if(w=='C') return "11";
		return "00";}if(q=='C'){
		if(w=='A') return "10";
		if(w=='B') return "11";
		return "00";}if(q=='D'){
		if(w=='F') return "11";
		return "00";}
	if(w=='A'){
		if(q=='B') return "11";
		if(q=='C') return "10";
		return "00";}if(q=='B'){
		if(q=='A') return "11";
		if(q=='C') return "11";
		return "00";}if(q=='C'){
		if(q=='A') return "10";
		if(q=='B') return "11";
		return "00";}if(q=='D'){
		if(q=='F') return "11";
		return "00";}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<3;i++){
		if(s[i]>='0'&&s[i]<='9') sa=sa*10+s[i]-48;
		else a=s[i];
		if(ss[i]>='0'&&ss[i]<='9') sb=sb*10+ss[i]-48;
		else b=ss[i];
	}if(sa==sb) cout<<1;
	else{
		cout<<"000";
		return 0;
	}//cout<<sa<<sb<<a<<b;
	cout<<ifside(a,b);
	return 0;
}//Trick||Treat!
