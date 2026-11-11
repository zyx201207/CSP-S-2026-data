//GZ-J00580 ·½å«Ïö 
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c1,c2;
	string s1,a;
	string s2,b;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		a.push_back(s1[i]);
		b.push_back(s2[i]);
	}
	if(a==b) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int x = s1[2];
	int y = s2[2];
	if((x>int('C')&&y>int('C'))||(x<=int('C')&&y<=int('C'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((s1[2]-s2[2])==1||(s2[2]-s1[2])==1) cout<<1;
	else{
		cout<<'0';
		return 0;
	}
}
