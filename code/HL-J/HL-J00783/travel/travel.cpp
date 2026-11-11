#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int x1=s1[2],x2=s2[2];
	if(abs(x1-x2)==1&&x1+1!=68&&x1-1!=67){
		cout<<"11";
	}else if(abs(x1-x2)==2&&x1==65&&x2==67||abs(x1-x2)==2&&x1==67&&x2==65){
		cout<<"10";
	}else{
		cout<<"00";
	}
	return 0;
}