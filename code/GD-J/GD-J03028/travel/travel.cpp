#include<bits/stdc++.h>
using namespace std;
int toint(string s){
	int sum=0;
	for(int i=0;i<2;i++){
		if(i==0&&s[i]==0)continue;
		sum+=(s[i]-'0')*pow(10,i);
	}
	return sum;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin >> a1>>a2>>b1>>b2;
	int ls[4]={};
	//是否在同一车厢 
	if(a1!=b1){
		cout << ls[0]<<ls[1]<<ls[2]<<ls[3];
		return 0;

	}
	else{
		ls[0]=1; 
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			ls[1]=1;
			if(a2[2]=='A'){
				if(b2[2]=='B'||b2[2]=='C')ls[2]=1;
			}
			else if(a2[2]=='B'){
				if(b2[2]=='A'||b2[2]=='C')ls[2]=1;
			
			}
			else if(a2[2]=='C'){
				if(b2[2]=='B'||b2[2]=='A')ls[2]=1;
					
			}
			else if(a2[2]=='D'){
				if(b2[2]=='E')ls[2]=1;
				
			}
			else if(a2[2]=='E'){
				if(b2[2]=='D')ls[2]=1;
				
			}
		}
			if(a2[2]=='A'){
				if(b2[2]=='B'){
					if(a2[0]==b2[0]&&a2[1]==b2[1])ls[3]=1;
				}
				else{
					if(b2[2]=='A'){
						string s1=s1+a2[0]+a2[1];
						string s2=s2+b2[0]+b2[1];
						int n1=toint(s1);
						int n2=toint(s2);
						if(n2==n1-1||n2==n1+1){
							ls[3]=1;
						}
					}
				}
			}
			if(a2[2]=='B'){
				if(b2[2]=='A'||b2[2]=='C'){
					if(a2[0]==b2[0]&&a2[1]==b2[1])ls[3]=1;
				}
				else{
					if(b2[2]=='B'){
						string s1=s1+a2[0]+a2[1];
						string s2=s2+b2[0]+b2[1];
						int n1=toint(s1);
						int n2=toint(s2);
						if(n2==n1-1||n2==n1+1){
							ls[3]=1;
						}
					}
				}
			}
			if(a2[2]=='C'){
				if(b2[2]=='B'){
					if(a2[0]==b2[0]&&a2[1]==b2[1])ls[3]=1;
				}
				else{
					if(b2[2]=='C'){
						string s1=s1+a2[0]+a2[1];
						string s2=s2+b2[0]+b2[1];
						int n1=toint(s1);
						int n2=toint(s2);
						if(n2==n1-1||n2==n1+1){
							ls[3]=1;
						}
					}
				}
			}
			if(a2[2]=='D'){
				if(b2[2]=='E'){
					if(a2[0]==b2[0]&&a2[1]==b2[1])ls[3]=1;
				}
				else{
					if(b2[2]=='D'){
						string s1=s1+a2[0]+a2[1];
						string s2=s2+b2[0]+b2[1];
						int n1=toint(s1);
						int n2=toint(s2);
						if(n2==n1-1||n2==n1+1){
							ls[3]=1;
						}
					}
				}
			}
			if(a2[2]=='E'){
				if(b2[2]=='D'){
					if(a2[0]==b2[0]&&a2[1]==b2[1])ls[3]=1;
				}
				else{
					if(b2[2]=='E'){
						string s1=s1+a2[0]+a2[1];
						string s2=s2+b2[0]+b2[1];
						int n1=toint(s1);
						int n2=toint(s2);
						if(n2==n1-1||n2==n1+1){
							ls[3]=1;
						}
					}
				}
			}
	}
	cout << ls[0]<<ls[1]<<ls[2]<<ls[3];
	return 0;
} 
