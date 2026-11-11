#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int n1=0,n2=0;
	for(int i=0;i<c1.size();i++){
		n1=n1*10+c1[i]-'0';
	}
	for(int i=0;i<c2.size();i++){
		n2=n2*10+c2[i]-'0';
	}
	if(n1!=n2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	n1=0,n2=0;
	for(int i=0;i<s1.size()-1;i++){
		n1=n1*10+s1[i]-'0';
	}
	for(int i=0;i<s2.size()-1;i++){
		n2=n2*10+s2[i]-'0';
	}
	if(n1!=n2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	char w1=s1[2],w2=s2[2];
	n1=w1-'A',n2=w2-'A';
	if(n1<=2&&n2<=2 || n1>2&&n2>2){
		cout<<"1";
		if(abs(w1-w2)==1){
			cout<<"1";
			return 0;
		}
		cout<<"0";
		return 0;
	}
	cout<<"00";
	return 0;
}
