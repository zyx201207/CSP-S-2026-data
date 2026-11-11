#include<bits/stdc++.h>
using namespace std;
char s1[5],s2[5],c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		s1[1]=x[0];
		s1[2]=x[1];
		c=x[2];
		s2[1]=y[0];
		s2[2]=y[1];
		d=y[2];
		if(s1[1]==s2[1] && s1[2]==s2[2]){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
		if(c=='A' && d=='B' || c=='A' && d=='C' || c=='B' && d=='A'  || c=='B' && d=='C' || c=='C' && d=='A' || c=='C' && d=='B' || c=='D' && d=='F' || c=='F' && d=='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
		if(c=='A' && d=='B' || c=='B' && d=='A' || c=='B' && d=='C' || c=='C' && d=='B' || c=='D' && d=='F' || c=='F' &&d=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	return 0;
} 
