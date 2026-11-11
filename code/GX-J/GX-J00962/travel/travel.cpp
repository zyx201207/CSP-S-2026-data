#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int a,b;
string s1,s2,ans;
int main()
{
		freopen("travel1.in","r",stdin);
		freopen("travel1.answer","w",stdout);
		scanf("%d",&a);cin>>s1;
		scanf("%d",&b);cin>>s2;
		if(a==b) ans +="1";else {printf("0000");return 0;}
		if(s1==s2) printf("1111");
		else {if(s1[0]==s2[0]&&s1[1]==s2[1]) ans+="1";
				else {cout<<ans+"000";return 0;}}
		char t[5]={'A','B','C','D','E'};
		int k1,k2;
		for(int j=0;j<=4;j++) if(s1[2]==t[j]) k1=j;
		for(int j=0;j<=4;j++) if(s2[2]==t[j]) k2=j;
		if((k1<=2&&k2<=2) || (k1>=3&&k2>=3)) {
			ans+="1";
			if(abs(k2-k1)==1){
				if((k1!=3&&k2!=4)||(k1!=4&&k2!=3)) {cout<<ans+"1";}
				else {cout<<ans+"0";}}return 0;}
		else {cout<<ans+"00";return 0;}
		return 0;
}
