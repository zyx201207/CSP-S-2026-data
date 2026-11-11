#include<bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
int p=0;
int o=0;
int r=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	if(c1[1]=='1'&&c1[2]=='6')cout<<0;
	else if(c1[0]=='0'&&c1[1]=='1'&&c1.size()==2)cout<<0;
	else{
	cout<<1;
	p=1;
	}
	}
	else if(c1!=c2){
	cout<<0;
	}
    if(p==1){
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
    cout<<1;
    o=1;
	}
	else cout<<0;
	}
	else if(p!=1)cout<<0;
	if(o==1&&r==0){
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
	cout<<1;
	r=1;
	}
	else if(s2[2]=='D'||s2[2]=='F') cout<<0;
}
}
	else if(o!=1)cout<<0;
	if(r==1){
	if(s1[2]=='A'){
	if(s2[2]=='B')cout<<1;
	else cout<<0;
	}
	if(s1[2]=='B'){
	if(s2[2]=='A'||s2[2]=='C')cout<<1;
	else cout<<0;
	}
	if(s1[2]=='C'){
	if(s2[2]=='B')cout<<1;
	else cout<<0;
	}
	if(s1[2]=='D'){
	if(s2[2]=='F')cout<<1;
	else  cout<<0;
	}
	if(s1[2]=='F'){
	if(s2[2]=='D')cout<<1;
	else cout<<0;
	}
	}
	else if(r==0)cout<<0;
	return 0;
} 
