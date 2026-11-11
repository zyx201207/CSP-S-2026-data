//GZ-J00141 自强中学 赵浩然 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s1,s2;
int c1,c2;
string pai1,pai2;
bool ans1=0,ans2=0,ans3=0,ans4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		ans1=1;
		cout<<1;
	}else cout<<0;
	
	for(int i=0;i<2;i++){
		pai1[i]=s1[i];
	}
	for(int i=0;i<2;i++){
		pai2[i]=s2[i];
	}
	bool f=1;
	for(int i=0;i<2;i++){
		if(pai1[i]!=pai2[i]) f=0;
	}
	if(ans1&&f){
		ans2=1;
		cout<<1;
	}else cout<<0;
	
	if((((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A'))
	||((s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D')))
	&&ans1&&ans2){
		ans3=1;
		cout<<1;
	}else cout<<0;
	
	if(((s1[2]=='A'&&s2[2]=='B')
	||(s1[2]=='B'&&s2[2]=='A')
	||(s1[2]=='B'&&s2[2]=='C')
	||(s1[2]=='C'&&s2[2]=='B')
	||(s1[2]=='D'&&s2[2]=='F')
	||(s1[2]=='F'&&s2[2]=='D'))
	&&ans1&&ans2&&ans3){
		ans4=1;
		cout<<1;
	}else cout<<0;
	
	
	
	
	return 0;
}


