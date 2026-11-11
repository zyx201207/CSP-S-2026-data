#include<iostream>
using namespace std;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int c=int((c2[0]-'0')*10)+int(c2[1]-'0');
	int s=int((s2[0]-'0')*10)+int(s2[1]-'0');
	if(c==s){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(c2[2]>='A'&&c2[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		if(int(c2[2]-s2[2])==1){
			cout<<1<<1;
	    }
		if(int(s2[2]-c2[2])==1) cout<<1<<1;
		else{
			cout<<1<<0;
			return 0;	
		}
	}
	else if(c2[2]>='D'&&c2[2]<='F'&&s2[2]>='D'&&s2[2]<='F') cout<<1<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	return 0;
}
