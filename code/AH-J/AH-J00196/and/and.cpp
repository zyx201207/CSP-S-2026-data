#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ma,c,k=1;
string s[200010],s1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		string w;
		while(x!=0){
			char t=x%2+'0';
			s[i]=t+s[i];
			x=x/2;
		}
		y=s[i].size();
		if(y>ma) ma=y;
	}
	for(int i=1;i<=ma;i++){
		int c;
		for(int j=1;j<=n;j++) c=c+(s[i][ma]-'0');
		if(c>=m) s1='1'+s1;
		else s1='0'+s1;
	}
	y=s1.size();
	for(int i=1;i<=y;i++){
		c=s1[i]*k+c;
		k=k*2;
	}
	cout<<c;
	return 0;
}
