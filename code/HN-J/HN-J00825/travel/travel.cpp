#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int s[10]={1,1,1,0,0};
int sum(string x){
	int ans=0;
	for(int i=0;i<2;i++){
		ans=ans*10+(x[i]-'0');
	}
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	int sn1=sum(s1);
	int sn2=sum(s2);
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(sn1==sn2){
		cout<<1;
		if(s[s1[2]-'A']==s[s2[2]-'A']){
			cout<<1;
			if(abs(s1[2]-s2[2])==1){
				cout<<1;
				return 0;
			}
		}
		else{
			cout<<"00";
			return 0; 
		}
	}
	else{
		cout<<"00";
	}
	if(s1[2]==s2[2]&&abs(sn1-sn2)==1){
		cout<<1;
	} 
	else{
		cout<<0;
	}
	return 0;
}
