#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int cnt=0,sum=0,e,f;
	for(int i=0;i<a.size();i++)
	if(a[i]=c[i])
	cnt++;
	if(cnt=a.size())
	cout<<1;
	else
	cout<<0;
	for(int i=0;i<b.size();i++)
	if(b[i]=d[i])
	sum++;
	if(sum=b.size())
	cout<<1;
	else
	cout<<0;
	for(int j=0;j<b.size();j++)
	if(b[j]=d[j])
	e++;
	if(e=b.size())
	cout<<1;
	else
	cout<<0;
	for(char g=0;g<b.size();g++)
	if(b[g+1]==d[g]||b[g-1]==d[g])
	f++;
	if(b[g]=d[g])
	cout<<1;
	else
	cout<<0;
	return 0;
}
