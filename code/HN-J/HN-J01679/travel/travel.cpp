#include<bits/stdc++.h>
using namespace std;
bool ifguodao(char s){
	if(s=='F'||s=='D') return 1;
	else return 0;
}
char ifxiangling(char s){
	if(s=='F') return 'D';
	else if(s=='D') return 'F';
	else if(s=='C') return 'B';
	else if(s=='A') return 'B';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	int sum1=0,sum2=0;
	for(int i=0;i<2;i++){
			if(s1[i]>='0'){
				sum1=sum1*10+(s1[i]-'0');
			}
			if(s2[i]>=0){
				sum2=sum2*10+(s2[i]-'0');
			}
		
	}
	if(sum1==sum2&&c1==c2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&sum1==sum2&&ifguodao(s1[2])==ifguodao(s2[2])) cout<<"1";
	else cout<<"0";
	if(c1==c2&&sum1==sum2&&ifguodao(s1[2])==ifguodao(s2[2])){
		if(s1[2]=='B'){
			if(s2[2]=='C'||s2[2]=='A') cout<<"1";
			else cout<<"0";
		}
		else if(s2[2]=='B'){
			if(s1[2]=='C'||s1[2]=='A') cout<<"1";
			else cout<<"0";
		}
		else if(ifxiangling(s1[2])==s2[2]&&ifxiangling(s2[2])==s1[2]) cout<<"1";
		else cout<<"0";
	}else cout<<"0";
	return 0;
}
