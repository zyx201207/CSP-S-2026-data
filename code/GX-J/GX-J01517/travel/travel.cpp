#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a_1,b_1,a_2,b_2;
	bool tonchexiang=0,tonpai=0,tonce=0,xiangling=0;
	int a,b,c,d;
	cin>>a_1>>b_1>>a_2>>b_2;
	/*a=(a_1[0]-49)*10;//+;
	a+=a_1[1]-49;
	b=(b_1[0]-49)*10;//+(b_1[1]-49);
	b+=b_1[1]-49;*/
	if(a_1==a_2)
		tonchexiang=1;
	else
		tonchexiang=0;
	if(b_1[0]==b_2[0]&&b_1[1]==b_2[1])
        tonpai=1;
    else
        tonpai=0;
    if(abs(b_1[2]-b_2[2])<2)
        xiangling=1;
    else
        xiangling=0;
    if(b_1[2]=='c'&&b_2[2]=='d'||b_1[2]=='d'&&b_2[2]=='c')
        tonce=0;
    else
        tonce=1;
	cout<<tonchexiang<<tonpai<<tonce<<xiangling;
	return 0;
}
