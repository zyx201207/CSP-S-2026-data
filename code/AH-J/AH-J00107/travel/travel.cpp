#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1.size()!=c2.size()){
		cout<<"0000";
		return 0;
	}else{
		for(int i=0;i<c1.size();i++){
			if(c1[i]!=c2[i]){
				cout<<"0000";
				return 0;
			}	
		}
		cout<<1;
	}	
	string temp1,temp2;
	char x,x1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
				temp1+=s1[i];
		}	
		if(s1[i]>='A'&&s1[i]<='F'){
				x=s1[i];
		}		
	}	
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9'){
				temp2+=s2[i];
		}	
		if(s2[i]>='A'&&s2[i]<='F'){
				x1=s2[i];
		}		
	}	
	if(temp1.size()!=temp2.size()){
		cout<<"000";
		return 0;
	}else{
		for(int i=0;i<temp1.size();i++){
			if(temp1[i]!=temp2[i]){
				cout<<"000";
				return 0;
			}	
		}
		cout<<1;
	}			
	if((x<='F'&&x>='D'&&x1<='F'&&x1>='D')||(x>='A'&&x<='C'&&x1>='A'&&x1<='C')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}	
	int ans=x-'A',ans2=x1-'A';
	if(ans-1==ans2||ans2-1==ans){
		if((ans==2&&ans2==3)||(ans2==3&&ans==2)){
			cout<<0;
		}else{
			cout<<1;
		}		
	}else{
		cout<<0;
	}	
	return 0;
}
