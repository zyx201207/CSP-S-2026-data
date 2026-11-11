#include<bits/stdc++.h>
using namespace std;
int cnt,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]==c2[i]) cnt++;
	}
	if(cnt==c1.size()) cout<<1;
	else{
		cout<<0;
		f=1;
	} 
	cnt=0;
	
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9' && s2[i]>='0'&&s2[i]<='9'){
			if(s1[i]==s2[i]) cnt++;
		}
	}
	if(cnt==2&&f==0) cout<<1;
	else{
		cout<<0;
		f=1;
	} 
	
	char a,b;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='A'&&s1[i]<='F') a=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='A'&&s2[i]<='F') b=s2[i];
	}
	if(int(a)<=int('C')&&int(b)<=int('C')&&f==0 || int(a)>int('C')&&int(b)>int('C')&&f==0){
		cout<<1;
	}
	else{
		cout<<0;
		f=1;
	} 
	
	if(int(a)<=int('C')&&int(b)<=int('C')&&f==0){
		int l=max(int(a),int(b))-min(int(a),int(b));
		if(l==1) cout<<1;
		else cout<<0;
		return 0;
	}
	else if(int(a)>int('C')&&int(b)>int('C')&&f==0){
		cout<<1;
		return 0;
	}
	else cout<<0;

	return 0;
}
