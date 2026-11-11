#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool think(char a){
	if(a=='A'||a=='B'||a=='C'){
		return 1;
	}return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >>s2;
	if(c1==c2){
		cout<<1;
		string b="",a="";
		a+=s1[0];
		a+=s1[1];
		b+=s2[0];
		b+=s2[1];
		if(a==b){
			cout<<1;
			if(think(s1[2])==think(s2[2])){
				cout<<1;
				if((think(s1[2])==think(s2[2]))&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
		else{cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
