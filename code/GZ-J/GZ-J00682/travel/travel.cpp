//GZ-J00682 个人报名 赵世福
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","i",stdin);
	freopen("travel.out","u"，stdin);
	int c1,c2,c3,c4;
	char s1,s2;
	cin>>c1>>c2>>s1>>c3>>c4>>s2;
	int i=s1,j=s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c2=c4){
		if(i-j==2||i-j==-2){
			if(i-j==1||i-j==-1){
				cout<<1111;
			}else cout<<1110;
		}else{
			cout<<"1100";
			return 0;
		}
	}
} 
return 0;
