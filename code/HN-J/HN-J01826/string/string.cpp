#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l=0,r=0;
	int n,ans=0;
	char c[10001];
	long long a[200001];
	char ch;
	cin >>n;
	for(int i=0;i<n;i++){	
		cin >> a[i]>>ch;
		l=r;
		r+=a[i];
		for(int i=l;i<=r;i++)
			c[i]=ch;
	}
	for(int l=1;l<=floor(r/2);l++)
		if(c[int(floor(r*1.0/2)-l)]!=c[int(floor(r*1.0/2)+l)])
			ans++;
	cout<<ans;
	return 0;
} 
