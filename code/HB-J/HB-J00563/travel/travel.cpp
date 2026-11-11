#include<bits/stdc++.h>
using namespace std;
string x_1,x_2;
string y_1,y_2;
char v[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x_1>>y_1>>x_2>>y_2;
	if(x_1==x_2)v[1]='1';
	else {
		cout<<"0000";
		return 0;
	}
	if(y_1[0]==y_2[0]&&y_1[1]==y_2[1])v[2]='1';
	else v[2]='0';
	int a,b;
	if(y_1[2]=='A'||y_1[2]=='B'||y_1[2]=='C')a=1;
	else a=0;
	if(y_2[2]=='A'||y_2[2]=='B'||y_2[2]=='C')b=1;
	else b=0;
	if(a==b&&v[2]=='1')v[3]='1';
	else v[3]='0';
	if(v[3]=='1'){
		if(b==0)v[4]='1';
		else{
			int r=y_1[2]-'A';
			int t=y_2[2]-'A';
			int f=abs(r-t);
			if(f==1)v[4]='1';
			else v[4]='0';
		}
	}
	else v[4]='0';
	cout<<v[1]<<v[2]<<v[3]<<v[4];
}
