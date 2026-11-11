#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t=0;
	char c;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c;
		for(int j=1;j<=a[i];j++)
			s+=c;
	}
  //cout<<s<<endl;
	for(int i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-1-i])
		{
//			cout<<i<<s[i]<<" "<<s[s.size()-1-i]<<endl;
			t++;
		}
	cout<<t<<endl;
	return 0;
}
