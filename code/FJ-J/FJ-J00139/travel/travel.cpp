#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	int ans=0;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else{
		ans+=1;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]){
			ans+=1;
		}else{
			cout<<"1000"<<endl;
			return 0;
		}
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			ans+=1;
		}else{
			cout<<"1100"<<endl;
			return 0;
		}
	}else if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			ans+=1;
		}else{
			cout<<"1100"<<endl;
			return 0;
		}
	}
	if(s1[2]=='C'&&s2[2]=='A'){
		cout<<"1110"<<endl;
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='C'){
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<"1111"<<endl;
	return 0;
}
