#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,ans; 
bool check(string a,string b){
	if(a=="A" || a=="B" || a=="C"){
		if(b=="A" || b=="B" || b=="C"){
			return true;
		}else{
			return false;
		}
	}else{
		if(b=="D" || b=="F"){
			return true;
		}else{
			return false;
		}
	}
}
bool check_two(string a,string b){
	if(a=="A"){
		if(b=="B")return true;
	}else if(a == "B"){
		if(b=="A" || b=="C")return true;
	}else if(a == "C"){
		if(b=="B")return true;
	}else if(a=="D"){
		if(b=="F")return true;
	}else{
		if(b=="D")return true;
	}
	return false;
}

int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		ans = "0000";
		cout << ans;
		return 0;
	}else{
		ans+="1";
		string sl1,sl2;
		for(int i=0;i<=1;i++){
			sl1+=s1[i];
			sl2+=s2[i];
		}
		if(sl1 == sl2){
			ans+="1";
		}else{
			cout << "1000";
			return 0;
		}
		
		sl1 = s1[2];
		sl2 = s2[2];
		if(check(sl1,sl2))ans+="1";
		else {
			cout << "1100";
			return 0;
		}
		
		if(check_two(sl1,sl2)){
			ans+="1";
		}else{
			cout << "1110";
			return 0; 
		}
	}
	cout << ans;
	
	
	return 0;
}
