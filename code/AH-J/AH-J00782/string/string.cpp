#include<bits/stdc++.h>
using namespace std;
int n,a[10000009],c[1000000008];
string b;
int sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b;
		if(b[i]==b[i])
		continue;
		else
		sum+=a[i];
		
	}
	cout<<sum;
	
	return 0;
}
