#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
string c1,s1,c2,s2;
int ans1,ans2,ans3,ans4;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans2=1;
			if(s1[2]+s2[2]<=133&&max(s1[2],s2[2])-min(s1[2],s2[2])<=2){
				ans3=1;
				if(max(s1[2],s2[2])-min(s1[2],s2[2])==1)ans4=1;
			}
		}
	}
	
	
	cout<<ans1<<ans2<<ans3<<ans4;
}
