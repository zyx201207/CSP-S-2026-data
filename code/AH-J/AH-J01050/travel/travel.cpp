#include<bits/stdc++.h>
using namespace std;
long long c1,c2,len1,len2,a1,a2,c;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	len1=s1.size(),len2=s2.size();
	
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		for(long long i=0;i<len1;i++){
			if(s1[i]=='F') s1[i]='E';
			if(s1[i]<='9'&&s1[i]>='0') a1=a1*10+s1[i];
		}
		for(long long i=0;i<len2;i++){
			if(s2[i]=='F') s2[i]='E';
			if(s2[i]<='9'&&s2[i]>='0') a2=a2*10+s2[i];
		}
		c=(int)(s1[2]-'A')-(s2[2]-'A');
		if(a1!=a2){
			cout<<"1000";
		}else{
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E'))){
				if(abs(c)==1&&((s1[2]!='C'&&s2[2]!='D')||(s2[2]!='C'&&s1[2]!='D'))){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}
	}
	return 0;
}
