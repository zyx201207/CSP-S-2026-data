//GZ-J00161 遵义市第四初级中学 赖钰晗
#include<bits/stdc++.h>
using namespace std;
bool ans1 = 1,ans2 = 1,ans3= 1,ans4 =1;
int c1,c2;
string s1,s2;
int main(){
	//freopen("travel.in","w",stdin);
	//freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i = 1;i<=17;i++){
		for(int j = 1;j<=5;j++){
			if(c1 == c2)
				ans1=1;
			else
				ans1=0;
			if(s1[1]==s2[1]&&s1[2]==s2[2])
				ans2=1;
			else
				ans2 = 0;
			if(s1[i]==s2[j])
				ans3=1;
			else
				ans3 = 0;
			if(s1[j]==s2[j]&&s1[j+1]==s2[j]&&s1[j-1]==s2[j])
				ans3=1;
			else
				ans3 = 0;
			if(s1[i]==s2[j])
				ans4=1;
			else
				ans4 = 0;
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4; 
	return 0;
}
