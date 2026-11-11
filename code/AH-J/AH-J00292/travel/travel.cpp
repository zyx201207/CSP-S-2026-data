#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c1,c2;
string s1,s2;
bool f1=0,f2=0,f3=0,f4=0;
int main(){//100
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			LL ch1=s1[2],ch2=s2[2];
			if(ch1=='D'&&ch2=='F') f3=1,f4=1;
			else if(ch1=='F'&&ch2=='D') f3=1,f4=1;
			else if(ch1<'D'&&ch2<'D'){
				f3=1;
				if(abs(ch1-ch2)==1) f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
