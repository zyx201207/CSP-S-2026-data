#include <bits/stdc++.h>
using namespace std;
int main() {
	char c1[4],s1[4],c2[4],s2[4],a,b,c,d,ans=4;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%c%c%c",&c1[1],&c1[2],&a);
	scanf("%c%c%c%c",&s1[1],&s1[2],&s1[3],&b);
	scanf("%c%c%c",&c2[1],&c2[2],&c);
	scanf("%c%c%c%c",&s2[1],&s2[2],&s2[3],&d);
	if(c2[2]==c1[2]){
		cout<<1;ans--;
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<1;ans--;
			if(s1[3]>='D'&&s2[3]>='D'){
			cout<<1;ans--;
			if(s1[3]+1==s2[3]||s1[3]-1==s2[3]){
		if((s1[3]<='C'&&s2[3]<='C')){cout<<1;ans--;}
		else if(s1[3]>='D'&&s2[3]>='D'){
		cout<<1;ans--;}
		else for(int i=1;i<=ans;i++)
		cout<<0;
	}
	else for(int i=1;i<=ans;i++)
		cout<<0;
		}	
			else if((s1[3]<='C'&&s2[3]<='C')){
				cout<<1;ans--;
				if(s1[3]+1==s2[3]||s1[3]-1==s2[3]){
		if((s1[3]<='C'&&s2[3]<='C'))cout<<1,ans--;
		else if(s1[3]>='D'&&s2[3]>='D')cout<<1,ans--;
		else for(int i=1;i<=ans;i++)
		cout<<0;
	}
	else for(int i=1;i<=ans;i++)
		cout<<0;
			}
			else for(int i=1;i<=ans;i++)
		cout<<0;
		}
		else for(int i=1;i<=ans;i++)
		cout<<0;
	}
	else {
		for(int i=1;i<=ans;i++)
		cout<<0;
	}
	
}
