#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int x,y,z,a,b,c;
int f(string s){
	int x=0;
	for(int i=0;i<s.size();i++)
		x=x*10+(s[i]-'0');
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=f(c1),a=f(c2);
	y=f(s1.substr(0,2)),b=f(s2.substr(0,2));
	z=(s1[2]-'A'+1),c=(s2[2]-'A'+1);
	if(x==a){
		cout<<'1';
		if(y==b){
			cout<<'1';
			if((z<=3&&c<=3)||(z>3&&c>3)){
				cout<<'1';
				if(abs(z-c)==1||(z==4&&c==6)||(z==6&&c==4))
					cout<<'1';
				else
					cout<<'0';
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";	
	}
	else
		cout<<"0000";
	//cout<<'\n'<<x<<" "<<y<<" "<<z<<'\n'<<a<<" "<<b<<" "<<c;
	return 0;
}
