#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	string result;
	if(c1==c3){
		result+='1';
	}else{
		result+="0000";
	cout<<result<<endl;
	return 0;
    }
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		result+='1';
	}
	else{
		result+="000";
		cout<<result<<endl;
		return 0;
	}
	if(c2[2]<='C'&&c4[2]<='C'){
		result+='1';
	}else if(c2[2]=='F'||c2[2]=='D'){
		result+='1';
	}else{
		result+="00";
		cout<<result<<endl;
		return 0;
	}
	if(c2[2]==c4[2]+1||c2[2]==c4[2]-1){
		result+='1';
	}else{
		result+='0';
	}
	cout<<result<<endl;
	return 0;
}
