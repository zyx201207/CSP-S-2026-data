#include <bits/stdc++.h> 
using namespace std;

int main(){
	//输入 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,c3,s3;
	string c2_s,s2_s; 
	cin>>c1>>c2_s>>s1>>s2_s;
	//处理字符串
	c2=(c2_s[0]-'0')*10+(c2_s[1]-'0');
	s2=(s2_s[0]-'0')*10+(s2_s[1]-'0');
	c3=c2_s[2]-'A'+1;
	s3=s2_s[2]-'A'+1;
	//判断与输出 
	cout<<(c1==s1);
	cout<<(c2==s2);
	cout<<((c2==s2)&&((c3<=3&&s3<=3)||(c3>3&&s3>3)));
	cout<<(((c2==s2)&&((c3<=3&&s3<=3)||(c3>3&&s3>3)))&&(abs(c3-s3)==1));
}
