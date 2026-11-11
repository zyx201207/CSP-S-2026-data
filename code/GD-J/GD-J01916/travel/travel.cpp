#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]=1;
			char t1=s1[2],t2=s2[2];
			if((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1>='D'&&t1<='F'&&t2>='D'&&t2<='F')){
				ans[3]=1;
				if(t1>t2)swap(t1,t2);
				if((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')||(t1=='D'&&t2=='F'))ans[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}
