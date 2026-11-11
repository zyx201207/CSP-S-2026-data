#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cin>>n;
	long long a[n],ans=0,c=0;
	char b[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans+=a[i];
	}
	for(int j=1;j<=n;j++)
		if(b[j]!=b[1])
			c+=1;
	if(c==0)
	cout<<c<<'\n';
	else
		cout<<ans/2<<'\n';
	return 0;
}
