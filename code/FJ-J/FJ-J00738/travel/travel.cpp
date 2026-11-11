#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[4],s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3]>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<1;
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<1;
			if((s1[3]>='D'&&s2[3]>='D') || (s1[3]<='C'&&s2[3]<='C'))cout<<1;
			else cout<<0;
			if(abs(s1[3]-s2[3])==1&&s1[3]!='C'&&s1[3]!='D'&&s2[3]!='C'&&s2[3]!='D')cout<<1;
			else cout<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
