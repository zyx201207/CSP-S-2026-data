#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,s,ss,chexiang1,chexiang2;
int main(){
	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	cin>>c1>>s1>>c2>>s2;
 	s=s1[0]+s1[1]*10;
 	ss=s2[0]+s2[1]*10;
 	chexiang1=s1[2]-'A'+1;
 	chexiang2=s2[2]-'A'+1;
 	if(c1==c2)cout<<"1";
 	else cout<<"0";
 	if(c1==c2&&s==ss)cout<<"1";
 	else cout<<"0";
 	if(c1==c2&&s==ss&&((chexiang1>3&&chexiang2>3)||(chexiang1<=3&&chexiang2<=3))){
 		cout<<"1";
	}else cout<<"0";
	if(c1==c2&&s==ss&&((chexiang1>3&&chexiang2>3)||(chexiang1<=3&&chexiang2<=3))&&abs(chexiang1-chexiang2)==1){
		cout<<"1";
	}else cout<<"0";
 	return 0;
}
