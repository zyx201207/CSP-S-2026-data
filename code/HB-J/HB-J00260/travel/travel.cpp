#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,l1,l2;
char n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	l1+=s1[0],l1+=s1[1],n1=s1[2];
	l2+=s2[0],l2+=s2[1],n2=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}cout<<'1';
	if(l1!=l2){
		cout<<"000";
		return 0;
	}cout<<'1';
	if(n1>='A'&& n1<='C' && n2>='A'&& n2<='C'){
		cout<<'1';
		if(n1==n2+1 || n1==n2-1) cout<<'1';
		else cout<<'0';
	}
	else if((n1=='D'|| n1=='F') && (n2=='D'|| n2=='F')) cout<<"11";
	else cout<<"00";
	return 0;
}
