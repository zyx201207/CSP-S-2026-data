#include<bits/stdc++.h>
using namespace std;
int a1;
string s1;
int a2;
string s2;
int flag[10];
int ans1;
int ans2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(s1[2]>s2[2]){
		swap(s1,s2);
		swap(a1,a2);
	}
	ans1=(s1[0]-'0')*10+s1[1]-'0';
	ans2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1==a2){
		flag[1]=1;
	}
	if(a1==a2&&ans1==ans2){
		flag[2]=1;
	}
	if(a1==a2&&ans1==ans2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))){
		flag[3]=1;
	}
	if(a1==a2&&ans1==ans2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))){
		flag[4]=1;
	}
	for(int i=1;i<=4;i++){
		cout<<flag[i];
	}
	return 0;
}