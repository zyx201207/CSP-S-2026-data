#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	int num1=0,num2=0;
	char ch1=s1[2],ch2=s2[2];
	for(int i=0;i<2;i++){
		num1=num1*10+(s1[i]-'0');
		num2=num2*10+(s2[i]-'0');
	}
	if(c1==c2){
		cout<<1;
		if(num1==num2){
			cout<<1;
			if(((ch1=='A'||ch1=='B'||ch1=='C')&&(ch2=='A'||ch2=='B'||ch2=='C'))||((ch1=='D'||ch1=='E')&&(ch2=='D'||ch2=='E'))){
				cout<<1;
				if(abs(ch1-ch2)==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
