#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t1,t2;
int a,b,ans[5];
string c,d;
int val(string x) {
	if(x=="A") return 0;
	if(x=="B") return 1;
	if(x=="C") return 2;
	if(x=="D") return 3;
	if(x=="F") return 4;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t1=s1.substr(0,2),t2=s2.substr(0,2);
	c=s1.substr(2,1),d=s2.substr(2,1);
	a=val(c);
	b=val(d);
	if(c1==c2) {
		ans[1]=1;
		if(t1==t2) {
			ans[2]=1;
			if(a<=2&&b<=2||a>=3&&b>=3) {
				ans[3]=1;
				if(abs(a-b)==1) ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout<<ans[i];	
	



	return 0; 
}
