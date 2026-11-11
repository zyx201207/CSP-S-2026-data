#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans="0000";
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	char h1=s1[0],h2=s1[1],h3=s2[0],h4=s2[1];
	char w1=s1[2],w2=s2[2];
	
	if(c1==c2)
	{
		ans[0]='1';
		if(h1==h3&&h2==h4)
		{
			ans[1]='1';
			if((w1=='A'||w1=='B'||w1=='C')&&(w2=='D'||w2=='F')) ans[3]='0';
			else if((w2=='A'||w2=='B'||w2=='C')&&(w1=='D'||w1=='F')) ans[3]='0';
			else
			{
				ans[2]='1';
				if(w2<w1) swap(w1,w2);
				if(w1+1==w2) ans[3]='1';
			}
		} 
	}
	cout<<ans;
	return 0;
}
