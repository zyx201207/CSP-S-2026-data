#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else cout<<0;
	int n=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')n=n*10+(int(s1[i]-'0'));
		else break;
	}
	int m=0;
	for(int i=0;i<s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9')m=m*10+(int(s2[i]-'0'));
		else break;
	}
	if(n==m&&c1==c2)cout<<1;
	else cout<<0;
	int p=0;
	int l1=s1.size(),l2=s2.size();
	if((s1[l1-1]=='A'||s1[l1-1]=='B'||s1[l1-1]=='C')&&(s2[l2-1]=='A'||s2[l2-1]=='B'||s2[l2-1]=='C')||(s1[l1-1]=='D'||s1[l1-1]=='F')&&(s2[l2-1]=='D'||s2[l2-1]=='F')){
		p=1;
	}
	if(n==m&&p==1&&c1==c2)cout<<1;
	else cout<<0;
	if(s1==s2)cout<<0;
	else{
		char c=s1[l1-1];
		char s=s2[l2-1];
		int qp=0;
		if((n==m&&s==(char(c+1)))||(n==m&&s==(char(c-1)))||((n-1)==m&&s==c)||((n+1)==m&&s==c)){
			qp=1;
		}
		if(n==m&&p==1&&c1==c2&&qp==1)cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
