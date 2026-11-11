#include<bits/stdc++.h>
using namespace std;
string s;

//TYX
/*
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	dashang QAQ
	
	*/
int T[1000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	T['A']=1,T['B']=1,T['C']=1;
	T['D']=2,T['E']=2;
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}
    s+='1';
    int cnt1=0,cnt2=0;
    int len1=s2.size(),len2=s4.size();
    for(int i=0;i<len1-1;i++){
		cnt1*=10;
		cnt1+=(s2[i]-'0');
	}for(int i=0;i<len2-1;i++){
		cnt2*=10;
		cnt2+=(s4[i]-'0');
	}
	if(cnt1!=cnt2){
		cout<<s<<"000";
		return 0;
	}s+='1';
	int f1=T[s2[len1-1]],f2=T[s4[len2-1]];
	if(f1!=f2){
		cout<<s<<"00";
		return 0;
	}
	s+='1';
	if((s2[len1-1]=='A'&&s4[len2-1]=='C')||(s2[len1-1]=='C'&&s4[len2-1]=='A')){
	//	s+='1';
	cout<<s<<0;
	return 0;
	}
	s+='1';
	cout<<s;
    return 0;
}
