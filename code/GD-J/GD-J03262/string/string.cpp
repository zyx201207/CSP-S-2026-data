#include<iostream>
#include<cstdio>
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c[1001],ans=0;
	longlong a;
	string s;
	cin>>n;
	for(int i =0;i<n;i++){
		string c;
		cin>>a>>c;
		s=s+a*c;
	}
	for(int i =0;i<len(s);i++){
		if(!s[i]==s[len(s)-i-1]){
			s[len(s)-i-1]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
