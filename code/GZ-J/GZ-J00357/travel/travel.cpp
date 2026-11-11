//GZ-J00357 ¹ùÃÌÌÚ
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],pre[N];
string c1,s1,c2,s2;
bool flag=1;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1,flag==1;
	else cout<<0,flag=0;
	if(((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0')&&(flag==1))cout<<1;
	else cout<<0,flag=0;
	if((flag==0)||((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')))cout<<0,flag=0;
	else cout<<1;
	if((abs(s1[2]-s2[2])==1&&(s1[2]!='D'||s2[2]!='D'))&&(flag==1))cout<<1;
	else cout<<0,flag=0;
	return 0;
}
