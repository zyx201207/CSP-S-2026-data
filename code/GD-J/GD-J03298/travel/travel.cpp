#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,s3,s4;
char ch[]={'A','B','C'};
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2.substr(0,2)==s4.substr(0,2)){
			cout<<1;
			char c=s2[2],c1=s4[2];
			bool f=0,f1=0;
			for(int i=0;i<3;i++){
				if(ch[i]==c)f=1;
				if(ch[i]==c1)f1=1;
			}
			if(f==f1){
				cout<<1;
				if(char(c+1)==c1||char(c1+1)==c)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
