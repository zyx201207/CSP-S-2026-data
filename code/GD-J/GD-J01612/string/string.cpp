#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
long long ans;
int n,num[maxn];char c[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>num[i]>>c[i];
	int i=1,j=n;
	while(i<j)
	{
		int mn=min(num[i],num[j]);
		if(c[i]!=c[j]){
			ans+=mn;
		}
		num[i]-=mn;num[j]-=mn;
		if(!num[i])i++;
		if(!num[j])j--;
	}
	cout<<ans;
	return 0;
}
