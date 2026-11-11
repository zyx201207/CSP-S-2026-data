#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
	}
	else{
		a[1]=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			a[2]=1;
			if(s2[2]-65<3&&s4[2]-65<3||s2[2]-65>=3&&s4[2]-65>=3){
				a[3]=1;
				if(abs(s2[2]-s4[2])==1) a[4]=1;
				else a[4]=0;
			}
			else{
				a[3]=0;
				a[4]=0;
			}
		}
		else{
			a[2]=0;
			a[3]=0;
			a[4]=0;
			
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
} 
