#include<bits/stdc++.h>
using namespace std;
int p[2],l[2];
int main(){
		int a,b;cin>>a>>b;
		for(int i=0;i<=2;i++){
			cin>>p[i];
		}
			for(int i=0;i<=2;i++){
				cin>>l[i];
		}
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
		if(p[1]==l[1]){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
		if(p[1]==l[1]){
			if(p[2]=='D'&&l[2]=='L'||p[2]=='L'&&l[2]=='D'){
				cout<<"1";
			}else if(p[2]=='A'&&l[2]=='B'||p[2]=='B'&&l[2]=='A'||p[2]=='C'&&l[2]=='B'||p[2]=='B'&&l[2]=='C'||p[2]=='C'&&l[2]=='A'||p[2]=='A'&&l[2]=='C'){
				cout<<"1";
			}else{
				cout<<"00";
				return 0;
			}
		}else{
		cout<<"00";
		return 0;
		}
		if(p[2]=='A'&&l[2]=='B'||p[2]=='B'&&l[2]=='A'||p[2]=='C'&&l[2]=='B'||p[2]=='B'&&l[2]=='C'||p[2]=='D'&&l[2]=='L'||p[2]=='L'&&l[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	return 0;
}
