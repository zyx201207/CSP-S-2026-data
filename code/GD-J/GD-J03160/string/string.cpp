#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long c;
		char v;
		cin>>c>>v;
		while(c--)
		{
			s+=v;
		}
	}
	int k=0;
	for(int i=s.size()-1;i>k;i--)
		if(s[k++]!=s[i])sum++;
	cout<<sum;
	return 0;
}//68
