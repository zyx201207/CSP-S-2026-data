#include<bits/stdc++.h> 
using namespace std;
string s[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,cnt2=0;

	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string b;
		cin>>a>>b;

		for(int j=1+cnt;j<=cnt;j++){
			s[j]+=b; 
		}
		cnt+=a;		
	}

	for(int i=1;i<=cnt/2;i++){
		if(s[i]==s[cnt-i+1])
			cnt2=cnt2;
		else
			cnt2++;
		
	}
	cout<<cnt2;


	return 0;
}
