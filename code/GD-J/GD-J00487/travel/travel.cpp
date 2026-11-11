#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int len1 = s1.size();
	int len2 = s2.size();
	string ss1,ss2;
	for(int i = 0;i<len1-1;i++){
		ss1+=s1[i];
	}
	for(int i = 0;i<len2-1;i++){
		ss2+=s2[i];
	}
	char sit1 = s1[len1-1];
	char sit2 = s2[len2-1];
	if(c1 == c2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(ss1 == ss2)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((sit1 =='F'&&sit2 == 'D')||(sit1 == 'D'&&sit2 == 'F')||(sit1!='F'&&sit1!='D'&&sit2!='F'&&sit2!='D')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((sit1 =='F'&&sit2 == 'D')||(sit1 == 'D'&&sit2 == 'F')){
		cout<<1;
		return 0;
	}else if(sit1 - sit2 == 1||sit2 - sit1 == 1){
		cout<<1;
		return 0;
	}else{
		cout<<"0";
		return 0;
	}
	
	 
	
	return 0;
}
