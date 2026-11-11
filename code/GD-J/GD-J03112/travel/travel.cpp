#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,an="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]!=c2[1]||c1[0]!=c2[0]){
		cout<<an;
		return 0;
	}else an[0]='1';
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<an;
		return 0;
	}else an[1]='1';
	if((s1[2]<'D'&&s1[2]<'D')||(s1[2]>='D'&&s1[2]>='D')){
		an[2]='1';
	}else{
		cout<<an;
		return 0;
	}
	if(s1[2]<'D'){
		if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)an[3]='1';
	}else{
		if(s1[2]==s2[2]+2||s1[2]==s2[2]-2)an[3]='1';
	}
	cout<<an;
	return 0;
}

