//100 pts
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	int l1 = 0,l2 = 0;
	for (int i = 0;i<2;i++) l1 = l1*10+(s1[i]-'0'),l2 = l2*10+(s2[i]-'0');
	cout<<((c1==c2)&&(l1==l2));
	cout<<((c1==c2)&&(l1==l2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')));
	cout<<((c1==c2)&&(l1==l2)&&(((s1[2]<='C'&&s2[2]<='C')&&(abs(s1[2]-s2[2])==1))||(s1[2]>='D'&&s2[2]>='D')));
	return 0;
}
