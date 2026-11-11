#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	int n;
	cin>>n;
	string shu;
	long long shuo=0;
	long long ans=0;
	long long a[n];
	char s[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		for(int j=0;j<a[i];j++){
			shu+=s[i];
		}
		shuo+=a[i];
	}
	for(int i=0;i<=shuo/2-1;i++)
	{
		if(shu[i]!=shu[shuo-i-1])
		{
			ans+=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
