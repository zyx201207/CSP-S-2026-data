#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		string c;
		cin>>a>>c;
		for(int j=0;j<a;j++) s+=c;
	}
	int cnt=0;
	for(int l=0,r=s.size()-1;l<=r;l++,r--)
	{
		if(s[l]!=s[r]) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
