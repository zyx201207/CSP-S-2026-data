#include<bits/stdc++.h>
#define long long ll
using namespace std;
string c1,s1,c2,s2;
bool think(){
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') return false;
	}else{
		if(s2[2]=='D'||s2[2]=='F') return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout << "0000" << "\n";
	}else{
		cout << 1;
		string r,x;
		r=s1[0]+s1[1],x=s2[0]+s2[1];
		if(r!=x){
			cout << "000" << "\n";
		}else{
			cout << 1;
			if(!think()){
				cout << "00" << "\n";
			}else{
				cout << 1;
				if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
					cout << "0" << "\n";
				}else{
					cout << 1 << "\n";
				}
			}
		}
	}
	return 0;
}
