//GZ-J00257 ºúÌÚ·½ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2,s3="ABCDF";
	int a=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=a+1000;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a=a+100;
			if(s1[2]==s3[3]&&s2[2]==s3[4]||s1[2]==s3[4]&&s2[2]==s3[3]){
				a=a+11;
			}else if(s1[2]==s3[0]||s1[2]==s3[1]||s1[2]==s3[2]&&s2[2]==s3[0]||s2[2]==s3[1]||s2[2]==s3[2]){
					a=a+10;
				if(s1[2]==s3[0]&&s2[2]==s3[1]||s1[2]==s3[0]&&s2[2]==s3[1]||s1[2]==s3[1]&&s2[2]==s3[2]||s1[2]==s3[2]&&s2[2]==s3[1]) {
					a=a+1;
				};
			};
		};
	};
	cout<<a;
	return 0;
}
