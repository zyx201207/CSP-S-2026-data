#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string c1;
	string s2;
	string c2;
	cin>>s1>>c1>>s2>>c2;
	int sum=0,sum2=0,sum3=0,sum4=0;
    string s; 
    cin>>s;
	for(int i=2;i<=15;i++){
		cin>>c1[i]>>c2[i];
		if(c1[1]==c2[1] && c1[2]==c2[2]){
			sum+=1;	
		}
		}
	for(int i=1;i<=18;i++){
		cin>>s1[i]>>s2[i];
		if(s1[2]==s2[2] && s1[1]==s2[1]){
			sum2+=1;
		}
	}
	for(int i=1;i<=18;i++){
			if(s1[1]==s2[1] && s2[2]==s2[2] &&(s1[i]=='A' && s2[i]=='B' )|| (s1[i]=='A'&& s2[i]=='C')||(s1[i]=='B'&& s2[i]=='C')||(s1[i]=='D' &&  s2[i]=='F'))
			sum3+=1;
	}
	for(int i='A';i<='F';i++){
	if((s1[i]=='A'&&s2[i]=='B')|| (s1[i]=='B' && s1[i]=='C') || (s1[i]=='D' && s2[i]=='F')){
		sum4+=1;
	}
}
	for(int i=1;i<=4;i++){
		s[1]==sum;
		s[2]==sum2;
		s[3]==sum3;
		s[4]==sum4;
	}
	cout<<s;
	return 0;

} 
