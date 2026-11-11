#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	
	}
	string q="",q1="";
	char qq,qq1;
	for(int i=0;i<=s1.size()-1;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			q+=s1[i];
		}else{
			qq=s1[i];
		}
	}
	for(int i=0;i<=s2.size()-1;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			q1+=s2[i];
		}else{
			qq1=s2[i];
		}
	}
	if(q==q1){
		cout<<1;
		if((qq1>='A'&&qq1<='C'&&qq>='A'&&qq<='C')||(qq1>='D'&&qq1<='F'&&qq>='D'&&qq<='F')){
			cout<<1;
			if((qq1>='A'&&qq1<='C'&&qq>='A'&&qq<='C')){
				if(qq1+1==qq||qq1-1==qq){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<1;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
	}
	return 0;
} 
