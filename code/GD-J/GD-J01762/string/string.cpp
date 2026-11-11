#include<bits/stdc++.h>

using namespace std;

long long n,sum,ans;
long long a[200010];
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++) s=s+c[i];
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	
	cout << ans << endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
 } 
