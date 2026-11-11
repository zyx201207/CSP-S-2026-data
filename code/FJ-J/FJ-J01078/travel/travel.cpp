#include<bits/stdc++.h>
using namespace std;
int i;
int main(){
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	cout<<'1';
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
	cout<<'1';
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){cout<<'1';
	if(s1[2]<='C'&&s2[2]<='C'){
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)cout<<'1';else cout<<'0';}
	if(s1[2]>='D'&&s2[2]>='D'){
		if(s1[2]-s2[2]==2||s2[2]-s1[2]==2)cout<<'1';else cout<<'0';
	}
	}else for(i=1;i<=2;i++)cout<<'0';}
	else for(i=1;i<=3;i++)cout<<'0';}
	else for(i=1;i<=4;i++)cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}