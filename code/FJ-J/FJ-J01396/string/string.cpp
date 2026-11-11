#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int ans=0;
	int l=0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		l+=t;
		char a;
		cin>>a;
		for(int j=0;j<t;j++){
			s+=a;
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
