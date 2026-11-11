#include<bits/stdc++.h>
using namespace std;
string s,t,x,y;
long long n,i,a,c;
char ch;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>ch;
		while(a--)s.push_back(ch);
	}
	for(i=s.size()-1;i>=0;i--)t.push_back(s[i]);
	if(s==t){cout<<0;return 0;}
	int o=s.size()/2;
	for(i=0;i<o;i++){
		x.push_back(s[i]);
	}
	for(i=s.size()-1;i>x.size();i--)y.push_back(s[i]);
	for(i=0;i<y.size();i++)if(y[i]!=x[i])c++;
	cout<<c;
	return 0;
}
