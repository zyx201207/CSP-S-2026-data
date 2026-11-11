#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

void setio(string filename,string inSu=".in",string outSu=".out"){
	string in=filename+inSu;
	string out=filename+outSu;
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

inline int idx(char s[4]){
	if(s[0]=='0')
		return int(s[1]-'0');
	else
		return static_cast<int>(s[0]-'0')*10+static_cast<int>(s[1]-'0');
}

inline bool judge1(char c1,char c2){
	if(c1=='A' && c2=='B')
		return true;
	if(c1=='A' && c2=='C')
		return true;
	if(c1=='B' && c2=='C')
		return true;
	if(c1=='D' && c2=='F')
		return true;
	if(c2=='A' && c1=='B')
		return true;
	if(c2=='A' && c1=='C')
		return true;
	if(c2=='B' && c1=='C')
		return true;
	if(c2=='D' && c1=='F')
		return true;
	return false;
}

inline bool judge2(char c1,char c2){
	if(c1=='A' && c2=='B')
		return true;
	if(c1=='B' && c2=='C')
		return true;
	if(c1=='D' && c2=='F')
		return true;
	if(c2=='A' && c1=='B')
		return true;
	if(c2=='B' && c1=='C')
		return true;
	if(c2=='D' && c1=='F')
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	setio("travel");
	char s1[4],s2[4];
	int num1,num2;
	scanf("%d %s%d %s",&num1,s1,&num2,s2);
	int ans1=(num1==num2?1:0);
	printf("%d",ans1);
	int colme1=idx(s1),colme2=idx(s2);
	int ans2=((ans1==1)and(colme1==colme2))?1:0;
	printf("%d",ans2);
	int ans3=((ans2==1)and(judge1(s1[2],s2[2])))?1:0;
	printf("%d",ans3);
	int ans4=((ans3==1)and(judge2(s1[2],s2[2])))?1:0;
	printf("%d",ans4);
	return 0;
}
