#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int same1=(c1==c2?1:0);
	cout<<same1;
	int row1=stoll(s1.substr(0,2));
	int row2=stoll(s2.substr(0,2));
	int same2=(same1&&row1==row2?1:0);
	cout<<same2;
	int col1=s1[2]-64,col2=s2[2]-64;
	int same3=(same2&&((col1<=3&&col2<=3)||(col1>=4&&col2>=4))?1:0);
	cout<<same3;
	int same4=(same3&&abs(col1-col2)==1?1:0);
	cout<<same4;
	return 0;
}
