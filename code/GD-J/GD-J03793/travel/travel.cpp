#include<bits/stdc++.h>
using namespace std;
char a[4]={'A','B','C'};
char b[3]={'D','F'};
char c[3]={'A','B'};
char d[3]={'B','C'};
bool fun(char s1,char s2,char a0[],int len){
	int f1=0,f2=0;
	for (int i=0;i<len;i++){
		if (a0[i]==s1) f1=1;
		if (a0[i]==s2) f2=1;
	}
	if (f1==1&&f2==1) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2){
		cout<<"0000";
		return 0;
	}else cout<<"1";
	if (s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if (fun(s1[2],s2[2],a,4)||fun(s1[2],s2[2],b,3)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if (fun(s1[2],s2[2],b,3)||fun(s1[2],s2[2],c,3)||fun(s1[2],s2[2],d,3)) cout<<"1";
	else cout<<"0";
	return 0;
} 
