#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[10],b[10],c[10],d[10];
int p[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)a[i+1]=c1[i]-'0';
	for(int i=0;i<c2.size();i++)b[i+1]=c2[i]-'0';
	for(int i=0;i<s1.size();i++)c[i+1]=s1[i]-'0';
	for(int i=0;i<s2.size();i++)d[i+1]=s2[i]-'0';
	bool o[4]={1,1,1,1};
	if(s1[2]=='D'||s1[2]=='F')p[1]=1;
	if(s2[2]=='D'||s2[2]=='F')p[2]=1;
	if(c1!=c2)o[0]=0;
	if(o[0])cout<<1;
	else cout<<0;
	if(!o[0])
		cout<<0<<0<<0;
	else{
		if(c[1]==d[1]&&c[2]==d[2])
			cout<<1;
		else{
			cout<<0;
			o[1]=0;
		}
		if(o[1]&&p[1]==p[2])cout<<1;
		else{
			o[2]=0;
			cout<<0;
		}
		if(o[2]&&o[1]&&abs(c[3]-d[3])==1)cout<<1;
		else cout<<0;	
	}
	return 0;
}
