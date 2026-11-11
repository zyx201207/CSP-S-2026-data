#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r>>x1>>x;
	if(r1!=x1){
	cout<<"0000";
	return 0;
	}
	else cout<<"1";
	if(r[0]==x[0]&&r[1]==x[1])cout<<"1";
	else{
	cout<<"000";
	return 0;
	}
	if(((r[2]=='A'||r[2]=='B'||r[2]=='C')&&(x[2]=='A'||x[2]=='B'||x[2]=='C'))||((r[2]=='D'||r[2]=='F')&&(r[2]=='D'||r[2]=='F')))cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	int s=r[2],w=x[2];
	if(x[2]=='F')w--;
	if(r[2]=='F')s--;
	if(abs(s-w)==1)cout<<"1";
	else{
		cout<<'0';
		return 0;
	}
	return 0;
}
