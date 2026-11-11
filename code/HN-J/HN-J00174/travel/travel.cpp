#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0, b=0, c=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		b++;
		c++;
	}
	else cout<<"0000"; 
	if(c==1){
		for(int i=0;i<2;i++){
		if(s1[i]==s2[i]){
			a++; 
		} 
	}
	if(a==2){
		cout<<1;
	    b++;
	}
	else cout<<0;
	if(a==2){
		if(s1[2]<='C' &&  s1[2]>='A' && s2[2]<='C' && s2[2]>='A'){
		cout<<1;
		b++;
	}
	else if(s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F'){
		cout<<1;
	    b++;
	}
	else cout<<0;
	}
	else cout<<0;
	if(b==3){
		if(s1[2]-'A'+1==s2[2]-'A' or s2[2]-'A'+1==s1[2]-'A'){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	}
	return 0;
}
