#include<bits/stdc++.h>
using namespace std;
long long n,len[200001],sum;
char a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>len[i]>>a[i];
	int l=1,r=n;
	while(l<r)
	{
		if(len[l]<len[r])
		{
			if(a[l]!=a[r]) sum+=len[l];
			len[r]-=len[l];
			l++;
		}
		else if(len[l]>len[r])
		{
			if(a[l]!=a[r]) sum+=len[r];
			len[l]-=len[r];
			r--;
		}
		else
		{
			if(a[l]!=a[r]) sum+=len[l];
			l++,r--;
		}
	}
	cout<<sum;
	return 0;
}
