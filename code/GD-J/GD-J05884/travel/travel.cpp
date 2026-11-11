#include <bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
char s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	s1=aa[2];
	s2=bb[2];
	if(aa[0]==bb[0]&&aa[1]==bb[1]){
		if( (s1>='D'&&s2>='D') || (s1<='C'&&s2<='C') ){
			if((max(s1,s2)-min(s1,s2))==1&&max(s1,s2)!='D'){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1110";
				return 0;
			}
		}else{
			cout<<"1100";
			return 0;
		}
	}else{
		cout<<"1000";
		return 0;
	}
	return 0;
} 
