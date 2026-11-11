#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int lie=0,che=0;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		che=1;
		cout<<"1";
	}
	else cout<<"0";
	if(che&&s1[0]==s2[0]&&s1[1]==s2[1]){
		lie=1;
		cout<<"1";
	}
	else cout<<"0";
	char ch1=s1[2],ch2=s2[2];
	if(che&&lie&&ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C'){
		cout<<"1";
	}
	else if(che&&lie&&(ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F')){
		cout<<"1";
	}
	else cout<<"0";
	if(che&&lie&&ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C'){
		if(int(ch1)-int(ch2)==1||int(ch2)-int(ch1)==1)
			cout<<"1";
		else cout<<"0";
	}
	else if(che&&lie&&((ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D'))) cout<<"1";
	else cout<<"0";
	fclose(stdin);fclose(stdout);
	return 0;
}
