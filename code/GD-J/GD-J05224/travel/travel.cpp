#include<bits/stdc++.h>
using namespace std;
struct f{
	string cxy;
	string zww;
};
int pd1(string a,string b){
	if(a[0]==b[0] and a[1]==b[1]){
		return 1;
	}
	return 0;
}
int pd2(string a,string b){
	if(a[1]==b[1] and a[0]==b[0]){
		return 1;
	}
	return 0;
}
int pd3(string a,string b){
	if((a[2]=='F' || a[2]=='D') and (b[2]=='F' || b[2]=='D')){
		return 1;
	}
	else if((b[2]!='F' and b[2]!='D') and (a[2]!='F' and a[2]!='D')){
		return 1;
	}
	else{
		return 0;
	}
	return 0;
}
int pd4(string a,string b){
	if((a[2]=='C' and b[2]=='D') || (a[2]=='D' and b[2]=='C')){
		return 0;
	}
	if(a[2]+1==b[2] || a[2]-1==b[2]){
		return 1;
	}
		return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	f sz1[3]={};
	cin>>sz1[1].cxy>>sz1[1].zww;
	cin>>sz1[2].cxy>>sz1[2].zww;
	int q=1,w=1,e=1;
	if(pd1(sz1[1].cxy,sz1[2].cxy))cout<<1;
	else {
		cout<<0;
		q=0;
	}
	if(pd2(sz1[1].zww,sz1[2].zww)and q)cout<<1;
	else {
		cout<<0;
		w=0;
	}
	if(pd3(sz1[1].zww,sz1[2].zww)and q and w)cout<<1;
	else {
		cout<<0;
		e=0;
	}
	if(pd4(sz1[1].zww,sz1[2].zww)and q and w and e)cout<<1;
	else {
		cout<<0;
	}
	return 0;
} 
