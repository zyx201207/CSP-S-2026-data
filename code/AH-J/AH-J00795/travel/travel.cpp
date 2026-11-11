#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
	else cout<<0;
	
	for(int i=0;i<=1;i++){
		a=a*10+s1[i]-'0';
		b=b*10+s2[i]-'0';
	}
	
	if(c1==c2&&a==b) cout<<1;
	else cout<<0;
	
	if(c1==c2&&a==b&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) cout<<1;
	else cout<<0;

	if(c1==c2&&a==b&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&(s1[2]==s2[2]-1||s1[2]==s2[2]+1)) cout<<1;
	else cout<<0;
return 0;
}
