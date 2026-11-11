#include<bits/stdc++.h>
using namespace std;
long long  n,c,sum,ans;
char a;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>c>>a;
		sum+=c;
		for (int j=0;j<c;j++) s+=a;
		
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	if (s==s1) {
		cout<<0;
		return 0;
	}
	else
	{
		string s2=s1.substr(sum/2+1,sum-(sum/2+1));
		for (int i=sum/2+1;i<sum;i++)
		{
			if(s2[i-(sum/2+1)]!=s[i])  ans++;
		}
	}
	cout<<ans;
	return 0;
}
