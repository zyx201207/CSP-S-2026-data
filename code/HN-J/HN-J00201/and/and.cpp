#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	string a,s;
	for(int i=0;i<n;i++)cin>>a[i];
	long long ans;
	for(int c=0;c<m;c++){
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n;j++){
				s[c]=0;
				s[c]=max(s[c],a[j]);
			}
			if(s[c]==a[i])a[i]=0;
		}
	}
	for(int i=0;i<m;i++)cout<<s[i];
	ans=s[0];
	for(int i=0;i<m-1;i++)ans=(ans and s[i+1]);
	cout<<ans;
	return 0;
}
