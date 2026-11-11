#include<bits/stdc++.h>
using namespace std;
string b[100005],sz;
int a[100005];
long long n,js,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sz=b[1];
		if(sz==b[i])js++;
		ans+=a[i];
	}
	if(js==n) cout<<"0";
	else cout<<ans/2;
	return 0;
}
