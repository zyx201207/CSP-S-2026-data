#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string s3,s4;
    s3=s1.substr(0,2);
    s4=s2.substr(0,2);
    char ch1=s1[2];
	char ch2=s2[2];
    if(c1==c2){
		cout<<1;
		if(s3==s4){
			cout<<1;
			if(s3==s4&&(((ch1>='A'&&ch1<='C')&&(ch2>='A'&&ch2<='C'))||((ch1>='D'&&ch1<='F')&&(ch2>='D'&&ch2<='F')))){
				cout<<1;
				if(s3==s4&&(((ch1>='A'&&ch1<='C')&&(ch2>='A'&&ch2<='C'))||((ch1>='D'&&ch1<='F')&&(ch2>='D'&&ch2<='F')))&&((abs(ch1-ch2)==1)||(ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D'))){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
    return 0;
}
