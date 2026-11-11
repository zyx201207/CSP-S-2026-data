#include <bits/stdc++.h>
using namespace std;
string ss1,ss2;
int a,b;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    cin>>a>>ss1>>b>>ss2;
    char c=ss1[2];
    char d=ss2[2];
    if(a==b){
    	cout<<1;
    	if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
    		cout<<1;
		}
		if(c=='D'&&d=='F'||c=='F'&&d=='D'||c=='A'&&d=='B'||c=='B'&&d=='A'||c=='B'&&d=='C'||c=='C'&&d=='B'||c=='A'&&d=='C'||c=='C'&&d=='A'){
			cout<<1;
		}
		if(c=='D'&&d=='F'||c=='F'&&d=='D'||c=='A'&&d=='B'||c=='B'&&d=='A'||c=='B'&&d=='C'||c=='C'&&d=='B'){
			cout<<1;
		}
		if(ss1[0]!=ss2[0]||ss1[1]!=ss2[1]){
			cout<<0;
		}
		if(c=='A'&&d=='F'||c=='F'&&d=='A'||c=='B'&&d=='F'||c=='F'&&d=='B'||c=='C'&&d=='F'||c=='F'&&d=='C'||c=='D'&&d=='A'||c=='A'&&d=='D'||c=='D'&&d=='B'||c=='B'&&d=='D'||c=='C'&&d=='D'||c=='D'&&d=='C'){	
			cout<<0;
		}
		if(c=='A'&&d=='C'||c=='C'&&d=='A'){
			cout<<0;
		}
	}
	else{
		cout<<"0000";
	}
    return 0;
}
