#include<bits\stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
    for(int i=1;i<=3;i++){
    	if(s1[i]>='0'&&s1[i]<='9'){
    		a+=s1[i];
		}
	    if(s1[i]>='A'&&s1[i]<='F'){
    		c=s1[i];
		}
		if(s2[i]>='0'&&s2[i]<='9'){
    		b+=s2[i];
		}
		if(s2[i]>='A'&&s2[i]<='F'){
    		d=s2[i];
		}
	}
if(c1==c2){
		cout<<"1";
if(a==b){
		cout<<"1";
	}
else{
		cout<<"000";
		return 0;
	}
if((c=='A'&&d=='C')||(c=='C'&&d=='A'))
	cout<<"10";
	return 0;
if((c=='D'&&d=='C')||(d=='D'&&c=='C'))
	cout<<"00";
	return 0;
if((c=='A'&&d=='B')||(d=='B'&&c=='A'))
	cout<<"11";
	return 0;
if((c=='B'&&d=='C')||(d=='B'&&c=='C'))
	cout<<"11";
	return 0;
}
if((c>='D'||c<='E')&&(d>='D'||d<='E')){
	cout<<"11";
	return 0;
}
	return 0;
}
