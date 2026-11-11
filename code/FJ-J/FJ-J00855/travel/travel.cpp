#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,l1,l2;
char t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
	cout<<0<<0<<0<<0;return 0;}
	else cout<<1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0' && s1[i]<='9'){
			l1+=s1[i];
		}
		else t1=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0' && s2[i]<='9'){
			l2+=s2[i];
		}
		else t2=s2[i];
	}
	if(l1!=l2){
		cout<<0<<0<<0;return 0;
	}
	else cout<<1;
	if(t1>='D' && t2>='D'){
		cout<<1;
		if(abs(t1-t2)==2){
			cout<<1;
		}
		else cout<<0;
	}
	else if(t1<='C' && t2<='C'){
		cout<<1;
		if(abs(t1-t2)==1){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0<<0;
	return 0;
}
