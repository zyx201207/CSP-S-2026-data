#include<bits/stdc++.h>
using namespace std;
string a1,b1;
char a2,b2;
bool check(char i,char j){
	if(i=='A'||i=='B'||i=='C'){
		if(j=='A'||j=='B'||j=='C'){
			return true;
		}
	}
	if(i=='D'||i=='F'){
		if(j=='D'||j=='F'){
			return true;
		}
	}
	else{
		return false;
	}
}
bool checkin(char x,char y){
	if(x=='D'||x=='F'){
		if(y=='D'||y=='F'){
			return true;
		}
	}
	if(x-y==1||y-x==1){
		if(x!='D'&&y!='D'){
			return true;
		}
	}
	else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	for(int i=1;i<=1;i++){
		a1[i]=c1[i];
		b1[i]=s1[i];
	}
	a2=c2[2];
	b2=s2[2];
	cout<<a2<<' '<<b2<<endl;
	if(c1==s1){
		cout<<1;
		if(a1==b1){
			cout<<1;
			if(check(a2,b2)){
				cout<<1;
				if(checkin(a2,b2)){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
					cout<<0<<0;
				}
		}
		else{
					cout<<0<<0<<0;
				}
	}
	else{
					cout<<0<<0<<0<<0;
				}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
