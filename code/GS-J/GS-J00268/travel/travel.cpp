#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("r",travel.in,in);
	freopen("w",travel.out,out);
	int w,e;
	string s,s1;
	char h,h1;
	cin>>w>>s>>e>>s1;
	cout<<11;
	h=s[2];
	h1=s1[2];
	if((int(h)==65||int(h)==66||int(h)==67)&&(int(h1)==65||int(h1)==66||int(h1)==67)||(int(h)==68||int(h)==70)&&(int(h1)==68||int(h)==70)){
		cout<<10;
	}else{
		cout<<00;
	}
	fclose(travel.in);
	 }
