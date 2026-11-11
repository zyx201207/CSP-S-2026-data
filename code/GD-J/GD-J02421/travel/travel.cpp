#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		string a,b;
		a=a+s1[0]+s1[1];
		b=b+s2[0]+s2[1];
		if(a==b){
			cout<<1;
			char x=(char)s1[2],y=(char)s2[2];
			if((x=='A'&&y=='B')||(x=='A'&&y=='C')||(y=='A'&&x=='C')||(y=='A'&&x=='B')||x=='D'&&y=='F'||x=='F'||y=='D'){
				if(x=='C'&&y=='D'||x=='D'||y=='C'){
					cout<<"00";
					return 0;
				}
				cout<<1;
				if((x==y+1||x==y-1||x=='D'&&y=='F'||x=='F'&&y=='D')&&(x!='C'&&y!='D')&&(x!='D'&&y!='C')){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
} 
