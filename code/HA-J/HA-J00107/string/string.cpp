#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
//define int __int128
const int N=1e6,A=1e9;
int n,a[N],ans;
char c[N];
signed main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//freopen(".in","w",stdout);
	//freopen(".out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;)
	{
		ans+=(c[i]==c[j]?0:min(a[i],a[j]));
		if(a[i]>a[j]){a[i]-=a[j];j--;}
		else if(a[i]<a[j]){a[j]-=a[i];i++;}
		else{i++;j--;}
	}
	cout<<ans;
	return 0;
}

