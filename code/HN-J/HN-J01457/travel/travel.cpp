#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s1,s2,s3,s4;
int ans[10],cheak[300];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	cheak['A']=1;
	cheak['B']=1;
	cheak['C']=1;
	cheak['D']=2;
	cheak['F']=2;
	if(s1==s3){
		ans[1]=1;
		string num1="",num2="";
		num1+=s2[0];
		num1+=s2[1];
		num2+=s4[0];
		num2+=s4[1];
		if(num1==num2){
			ans[2]=1;
			char num3=s2[2],num4=s4[2];
			if(cheak[num3]==cheak[num4]){
				ans[3]=1;
				if(num3+1==num4||num3-1==num4){
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];

	return 0;
}
//预计过 1~20 测试点 
//预计分数：100 
