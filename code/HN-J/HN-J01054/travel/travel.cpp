#include<bits/stdc++.h>
using namespace std;
char s1,s2;
int c1,c2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s3>>s1>>c2>>s4>>s2;
	if(c1==c2){
		cout<<1;
		if(s3==s4){
			cout<<1;
			if(s1=='A'||s1=='B'||s1=='C'&&s2=='A'||s2=='B'||s2=='C') cout<<1;
			else if((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')) cout<<1;
			else cout<<0;
			int maxn=max(s1,s2),minn=min(s1,s2);
			if(minn+1==maxn&&minn!='C') cout<<1;
			else cout<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
