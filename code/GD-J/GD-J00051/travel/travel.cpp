#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f1,f2,f3,f4;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	f1=(c1==c2);
	f2=(s1.substr(0,2)==s2.substr(0,2))&&f1;
	if(s1[2]<='C'){
		f3=(s2[2]<='C')&&f2;
	}else {
		f3=(s2[2]>='D')&&f2;
	}
	if(s2[2]=='F') s2[2]='E';
	if(s1[2]=='F') s1[2]='E';
	f4=(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1)&&f3;
	cout<<(int)f1<<(int)f2<<(int)f3<<(int)f4<<endl;
	return 0;
} 
