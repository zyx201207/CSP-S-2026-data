#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m;
string s1,s2,c1,c2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	s3+=s1[0];s3+=s1[1];
	s4+=s2[0];s4+=s2[1];
	if(c1!=c2)cout<<"0000";
	else{cout<<"1";
		if(s3==s4){
			cout<<"1";
			if((s1[2]<='C' and s2[2]<='C') or (s1[2]>='D' and s2[2]>='D')){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1)cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}
