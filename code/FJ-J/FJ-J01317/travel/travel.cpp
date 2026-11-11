#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1=="01A"||s1=="01B"||s1=="01C"||s1=="01D"||s1=="01E"){
		if(s2=="01A"||s2=="01B"||s2=="01C"||s2=="01D"||s2=="01E"){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	if(s1=="01A"){
		if(s2=="01B"){
			cout<<"11";
		}else if(s2=="01C"){
			cout<<"10";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(s1=="01B"){
		if(s2=="01A"||s2=="01C"){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(s1=="01C"){
		if(s2=="01B"){
			cout<<"11";
		}else if(s2=="01A"){
			cout<<"10";
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(s1=="01D"){
		if(s2=="01F"){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(s1=="01F"){
		if(s2=="01D"){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

