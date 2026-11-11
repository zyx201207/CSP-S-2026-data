#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a=0,b=0,c=0,d=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)a++;
	else a=0;
	if(a==1){
		for(int i=1;i<=18;i++){
			if(s1[i]==s2[i]){
				b++;
				break;
			}
			else b=0;
		}
	}
	if(b==1){
		if(s1.size()==s2.size()){
			c++;
		}
		else c=0;
	}
	if(s1.size()=='A'&&s2.size()=='B'||s1.size()=='B'&&s2.size()=='C'||s1.size()=='D'&&s2.size()=='F'||s2.size()=='A'&&s1.size()=='B'||s2.size()=='B'&&s1.size()=='C'||s2.size()=='D'&&s1.size()=='F'){
			d++;
	}
	else d=0;
	cout<<a<<b<<c<<d;
	return 0;
}

