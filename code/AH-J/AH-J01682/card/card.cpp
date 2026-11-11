#include<bits/stdc++.h> 
using namespace std;
bool cmp(string x,string y){
	int s=0;
	for(int i=0;i<2;i++){
			if(x[i]==y[i]){
				s++;
			}
		}
	if(s==2){
		return true;
	}else{
		return false;
	}
}
bool cmp2(string x,string y){
	if(x[2]=='A'&&(y[2]=='B'||y[2]=='C')){
		return true;
	}
	if(x[2]=='B'&&(y[2]=='A'||y[2]=='C')){
		return true;
	}
	if(x[2]=='C'&&(y[2]=='B'||y[2]=='A')){
		return true;
	}
	if(x[2]=='D'&&y[2]=='F'||x[2]=='D'&&y[3]=='F'){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(a==c){
		cout<<"1";
		if(cmp(b,d)){
			cout<<"1";
			if(cmp2(b,d)){
				cout<<"1";
				int a1,b1;
				a1=b[2];
				b1=d[2];
				if(cmp2(b,d)&&((a1-b1)==1||(b1-a1)==1)){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
