//GZ-J00716 北京师范大学贵阳附属中学 邹骐骏;
#include<bits/stdc++.h>
using namespace std;
int f(string n){
	if(n[2]=='A' or n[2]=='B' or n[2]=='C'){
		return 1;
	}
	return 2;
}
int g(string n,string m){
	if(n[2]=='A' and m[2]=='B' or n[2]=='B' and m[2]=='A' or n[2]=='B' and m[2]=='C'){
		return 1;
	}
	if(n[2]=='F' and m[2]=='D' or n[2]=='D' and m[2]=='F'){
		return 1;
	}
	return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0,1]==c2[0,1]){
		if(s1[0,1]==s2[0,1]){
			if(f(s1)==f(s2)){
				if(g(s1,s2)==1){
					cout <<1<<1<<1<<1;
					return 0;
				}
				else{
					cout <<1<<1<<1<<0;
					return 0;
				}
			}
			else{
				cout <<1<<1<<0<<0;
				return 0;
			}
		}
		else{
			cout <<1<<0<<0<<0;
			return 0;
		}
	}
	else{
		cout <<0<<0<<0<<0;
		return 0;
	}
} 
