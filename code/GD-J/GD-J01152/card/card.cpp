#include<bits/stdc++.h>
#define tt long long
using namespace std;
int n,m;
char c;
string s,s3[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		s+=c;
	}
	for(int i=1;i<=n;i++){
		string s1=s,s2=" ";
		for(int j=i;j<=n;j++){
			tt p=s2.find(s[j-1]);
			if(s2[p]==s[j-1])s2=s2.substr(0,p);
			s2+=s[j-1];
		}
		s3[i]=s2;
	}
	for(int i=1;i<=m;i++){
		tt cnt=0;
		for(int j=1;j<=n;j++){
			if(s3[j].find(i+'0')!=-1)cnt++;
		}
		cout<<cnt<<' ';
	}
} 
