#include<bits/stdc++.h>
using namespace std;
#define Freopen(x) _Freopen(#x)
void _Freopen(string file){
	freopen((file+".in").c_str(),"r",stdin);
	freopen((file+".out").c_str(),"w",stdout);
}
void Fclose(){
	fclose(stdin);
	fclose(stdout);
}
string c1,s1,c2,s2;
bool f1=0,f2=0;
bool ans1,ans2,ans3,ans4;
int main(int argc,char** argv){
//	Freopen(and);
//	Freopen(card);
//	Freopen(string);
	Freopen(travel);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
	}else{
		ans1=0;
	}
	if(ans1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		ans2=1;
	}else{
		ans2=0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')f1=0;
	else f1=1;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')f2=0;
	else f2=1;
	if(ans2&&f1==f2){
		ans3=1;
	}else{
		ans3=0;
	}
	string x;
	x+=s1[2];
	x+=s2[2];
	if(ans3&&(x=="AB"||x=="BA"||
	x=="BC"||x=="CB"||x=="DF"||x=="FD")){
		ans4=1;
	}else{
		ans4=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	Fclose();
	return EXIT_SUCCESS; 
}
