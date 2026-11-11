#include<bits/stdc++.h>
using namespace std;
int a[10];
string s1,s2,s3,s4;	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	//cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
	if(s1==s3){
		a[1]=1;
		if(s2[0]==s4[0]&&s2[1]==s4[1]) {
			a[2]=1;
			if('A'<=s2[2]&&s2[2]<='C'&&'A'<=s4[2]&&s4[2]<='C'||'D'<=s2[2]&&s2[2]<='F'&&'D'<=s4[2]&&s4[2]<='F'){
				a[3]=1;
				if(s2[2]+1==s4[2]||s2[2]-1==s4[2])	a[4]=1;
			}	
		}		
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	} 
	return 0;
} 
