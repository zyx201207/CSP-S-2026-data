#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int l,r;
bool cmp(string x,string y){
	for(int i=0;i<l;i++){
		if(c1[i]!=c2[i])return false;
	}return true;
}
bool cmp1(string x,string y){
	for(int i=0;i<r-1;i++){
		if(s1[i]!=s2[i])return false;
	}return true;
}
bool cmp2(string x,string y){
	if(s1[r-1]<='C'&&s1[r-1]>='A'&&s2[r-1]>='A'&&s2[r-1]<='C')return true;
	else if((s1[r-1]=='F'||s1[r-1]=='D')&&(s2[r-1]=='F'||s2[r-1]=='D'))return true;
	else return false;
}
bool cmp3(string x,string y){
	if(s1[r-1]<='C'&&s1[r-1]>='A'&&s2[r-1]>='A'&&s2[r-1]<='C'&&abs(int(s1[r-1])-int(s2[r-1]))==1)return true;
	else if((s1[r-1]=='F'||s1[r-1]=='D')&&(s2[r-1]=='F'||s2[r-1]=='D')&&abs(int(s1[r-1])-int(s2[r-1]))==1)return true;
	else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	l=c1.size(),r=s1.size();
	if(cmp(c1,c2)==true)cout<<1;
	else{
		cout<<"0000";return 0;
	}
	if(cmp1(s1,s2)==true)cout<<1;
	else{
		cout<<"000";return 0;
	}
	if(cmp2(s1,s2)==true)cout<<1;
	else{
		cout<<"00";return 0;
	}
	if(cmp3(s1,s2)==true)cout<<1;
	else cout<<0;
	
	
	return 0;
} 
