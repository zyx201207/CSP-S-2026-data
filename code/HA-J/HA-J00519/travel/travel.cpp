#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	string a,b;
	char a1,b1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	} 
    else{
    	cout<<"0000";
    	return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9') a+=s1[i];
		if(s1[i]>='A'&&s1[i]<='F') a1=s1[i];
	}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9') b+=s2[i];
		if(s2[i]>='A'&&s2[i]<='F') b1=s2[i];
	}
	//cout<<" "<<a<<" "<<a1<<" "<<b<<" "<<b1;
	if(a==b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(a==b){
		if(a1>='A'&&a1<='C'&&b1>='A'&&b1<='C'||a1>='D'&&a1<='F'&&b1>='D'&&b1<='F'){
			cout<<1;
			if(a1>='D'&&a1<='F'&&b1>='D'&&b1<='F'){
				cout<<1;
			}else{
				if(a1=='A'&&b1=='B'||a1=='B'&&b1=='A'||a1=='B'&&b1=='C'||a1=='C'&&b1=='B'){
					cout<<1;
				}else{
					cout<<"0";
					return 0;
				}
			} 
		}else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
