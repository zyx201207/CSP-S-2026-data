#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a1>>c2>>s2>>a2;
	cout<<(c1==c2)<<((s1==s2)&&(c1==c2))<<(c1==c2&&s1==s2&&(a1-'A'<3)==(a2-'A'<3))<<(c1==c2&&s1==s2&&(a1-'A'<3)==(a2-'A'<3)&&((a1+1)==a2||(a1-1)==a2));
	return 0;
}
