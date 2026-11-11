#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c1,c2;
string s1,s2;
bool check(string s1,string s2){
	string t1="",t2="";
	for(int i=0;i<=1;++i)t1+=s1[i];
	for(int i=0;i<=1;++i)t2+=s2[i];
	return (t1==t2);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(check(s1,s2)){
			cout<<1;
			char ch1=s1[2];
			char ch2=s2[2];
			if((ch1<'D'&&ch2<'D')||(ch1>'C'&&ch2>'C')){
				cout<<1;
				if(abs(ch1-ch2)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
			//判断依据，要么两个字符都小于'D'要么两个字符都大于'C' 
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
