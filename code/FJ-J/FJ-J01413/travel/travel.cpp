#include<bits/stdc++.h>
#define ll long long
using namespace std;

	string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(!(c1==c2)){
		cout<<"0000\n";
		return 0;
	}
	cout<<"1";
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"000\n";
		return 0;
	}
	cout<<"1";
	char w1=s1[2],w2=s2[2];
	if(!(('A'<=w1&&w1<='C'&&'A'<=w2&&w2<='C')||('D'<=w1&&w1<='E'&&'D'<=w2&&w2<='E'))){
		cout<<"00\n";
		return 0;
	}
	cout<<"1";
	if(!((int(w1)+1==int(w2))||(int(w2)+1==int(w1)))){
		cout<<"0\n";
	}
	cout<<"1\n";
	return 0;
}
//T1
//拜拜咔邦！ 
//第三次来csp-j，我无疑是兴奋的
//I love ccf!
//I love ccf!
//I love ccf!
//I love ccf!
//I love ccf!
/*
	---		\		------	\       /	=====	-----	-----	=====	||
	 \		\		\	 \	 \     /	|		|		|		|		||
	 \		\		\	 \	  \   /		=====	|		|		=====	||
	 \		\		\	 \	   \ /		|		|		|		|		
	---		----	------		.		=====	-----	-----	|		。 
*/ 
