#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200001],cnt=0,n,r,l;
	char b[200001];
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
		cin>>b[i];
	}
	cnt/=2;
	l=1;
	r=n;
	while(cnt)
	{
		cnt--;
		if(b[l]!=b[r]) ans++;
		if(a[l]) a[l]--;
		else{
			l++;
			a[l]--;
		}
		if(a[r]) a[r]--;
		else{
			r--;
			a[r]--;
		}
	}
	cout<<ans;
	return 0;
}
