#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,e=0;
	cin>>n;
	long long a[n+1],ans=0;
	char c[n+1];
	cin>>a[1]>>c[1];
	ans+=a[1];
	for(int i=2;i<=n;i++){	
	cin>>a[i]>>c[i];
	ans+=a[i];
	if(c[i]!=c[i-1])
	e++;
	}
	if(e==0)
		cout<<0;
		else if(n==1)
		cout<<1;
	else if(n==2)
		cout<<min(a[1],a[2]);
		else
		cout<<ans/2;
} 
