#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	
	
	cin>>c1>>c2>>c3>>c4;
	
	if(c1==c3) a=1;
	char s1 = c2[2];
	char s2 = c4[2];
	int n1 = s1-'A'+1;
	int n2 = s2-'A'+1;
	//cout<<n1<<" "<<n2<<endl;
	if((c2[0] ==c4[0]&&c2[1]==c4[1])&&a==1) b=1;
	if(((n1>=1&&n1<=3&&n2>=1&&n2<=3)||(n1>=4&&n1<=5&&n2>=4&&n2<=5))&&b==1)
		c=1;
	if(n1>=4&&n1<=5&&n2>=4&&n2<=5&&b==1) d=1;
	if((n1>=1&&n1<=3&&n2>=1&&n2<=3)&&(b==1)){
		if(n1==2||n2==2) d=1;
	}
	cout<<a<<b<<c<<d;
	freopen("travel.out","w",stdout);
	return 0;
}
