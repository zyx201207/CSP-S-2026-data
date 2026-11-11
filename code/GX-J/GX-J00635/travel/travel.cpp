#include <bits/stdc++.h>
using namespace std;
int c1,c2,a[5];
string s1,s2;
bool f_h(string a,string b){
	for(int i=0;i<2;i++){
		if(a[i]!=b[i])return false;
	}
	return true;
	
}
bool f_b(string a,string b){
	char a1=a[2],b1=b[2];
	if((a1<='C'&&b1>='D')||(a1>='D'&&b1<='C'))return false;
	return true;
}
bool f_l(string a,string b){
	char a1=a[2],b1=b[2];
	if((a1=='D'&&b1=='F')||(a1=='A'&&b1=='B')||(a1=='B'&&b1=='C')||(a1=='F'&&b1=='D')||(a1=='B'&&b1=='A')||(a1=='C'&&b1=='B'))return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a[1]=1;
	if(f_h(s1,s2))a[2]=1;
	if(f_b(s1,s2))a[3]=1;
	if(f_l(s1,s2))a[4]=1;
	if(a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1)cout<<"1111";
	else if(a[1]==1&&a[2]==1&&a[3]==1&&a[4]==0)cout<<"1110";
	else if(a[1]==1&&a[2]==1&&a[3]==0)cout<<"1100";
	else if(a[1]==1&&a[2]==0)cout<<"1000";
	else cout<<"0000";
	return 0;
}
