#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2;
char a[4]={'X','A','B','C'};
int x1=0,x2=0,y1=0,y2=0,f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=x1*10+int(c1[0]-'0');
	x1=x1*10+int(c1[1]-'0');
	x2=x2*10+int(c2[0]-'0');
	x2=x2*10+int(c2[1]-'0');
	if(x1!=x2){
		cout<<"0000";
		return 0;
	}
	y1=y1*10+int(s1[0]-'0');
	y1=y1*10+int(s1[1]-'0');
	y2=y2*10+int(s2[0]-'0');
	y2=y2*10+int(s2[1]-'0');
	if(y1!=y2){
		cout<<"1000";
		return 0;	
	}
	for(int i=1;i<=3;i++){
		if(s1[2]==a[i]) f++;
		if(s2[2]==a[i]) f++;
	}
	if(f==1){
		cout<<"1100";
		return 0;
	}
	int m=int(s1[2]);
	int n=int(s2[2]);
	if(abs(m-n)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
