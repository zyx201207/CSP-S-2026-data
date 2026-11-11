#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string ss1,s1,ss2,s2;
int p1,r1,c1,p2,r2,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ss1>>s1>>ss2>>s2;
	p1=10*(ss1[0]-'0')+ss1[1]-'0';
	p2=10*(ss2[0]-'0')+ss2[1]-'0';
	r1=10*(s1[0]-'0')+s1[1]-'0';
	r2=10*(s2[0]-'0')+s2[1]-'0';
	c1=s1[2]-'A';
	c2=s2[2]-'A';
	bool ans1=(p1==p2);
	bool ans2=(ans1&&r1==r2);
	bool ans3=(ans2&&((c1<=2&&c2<=2)||(c1>=3&&c2>=3)));
	bool ans4=(ans3&&(((c1<=2&&c2<=2)&&abs(c1-c2)==1)||(c1>=3&&c2>=3)&abs(c1-c2)==2));
	cout<<ans1<<ans2<<ans3<<ans4; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

