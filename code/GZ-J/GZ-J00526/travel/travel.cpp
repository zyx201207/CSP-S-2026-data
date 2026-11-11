//GZ-J00526 袁金厚 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long c1,c2,s1,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1==c2)cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1==s2)cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1==s2&&((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>'C'&&b>'C')))
	cout<<'1';
	else cout<<'0';
	if(c1==c2&&s1==s2&&((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>'C'&&b>'C'))&&(a-b==1||b-a==1))
	cout<<'1';
	else cout<<'0';
	cout<<"\n";
	return 0;
} 
