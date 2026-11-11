#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travrl.in","r",stdin);
	freopen("travrl.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	int a[105],b[105];
	char x,y; 
	for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9') a[i]=s1[i];
			else x=s1[i];
		}
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9') b[i]=s2[i];
		else y=s2[i];
	}
	if(c1==c2){
		cout<<'1';
		int r,l;
		int cnt=0;
		for(int i=0;i<2;i++){
			if(a[i]==b[i]) cnt++;
		}
		if(cnt==2){
			cout<<'1';
			if(x=='A'&&y=='B'||x=='A'&&y=='C'||
			   x=='B'&&y=='A'||x=='B'&&y=='C'||
			   x=='C'&&y=='A'||x=='C'&&y=='B'||
			   x=='D'&&y=='F'||x=='F'&&y=='D')
			{
				cout<<'1';
				if(x+1==y||x-1==y||x==y-1||x==y-1||x=='D'&&y=='F'||x=='F'&&y=='D') cout<<'1';
				else cout<<'0';
			}
			else cout<<"00"; 
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
