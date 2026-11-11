#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c1,c3;
string c2,c4;
bool pai(string a,string b){
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	cout<<pai(c2,c4);
	if(pai(c2,c4)==1){
		if(c2[2]=='A'&&c4[2]=='B'){
			cout<<"11";
			return 0;
		}else if(c2[2]=='A'&&c4[2]=='C'){
			cout<<"10";
			return 0;
		}else if(c2[2]=='B'&&c4[2]=='A'){
			cout<<"11";
			return 0;
		}else if(c2[2]=='C'&&c4[2]=='A'){
			cout<<"10";
			return 0;
		}else if(c2[2]=='C'&&c4[2]=='B'){
			cout<<"11";
			return 0;
		}else if(c2[2]=='B'&&c4[2]=='C'){
			cout<<"11";
			return 0;
		}else if(c2[2]=='D'&&c4[2]=='F'){
			cout<<"11";
			return 0;
		}else if(c2[2]=='F'&&c4[2]=='D'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
