#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Max=2e5;
int n,len,ans;
int arr[Max+32];
char ch[Max+32];
int le[Max+32],ri[Max+32];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i]>>ch[i];
		len+=arr[i];
		le[i]=ri[i-1]+1;
		ri[i]=le[i]-1+arr[i];
	}
	int i=1,j=n,ldx=1,rdx=len;
	while(i<j)
	{
		int tmp=min(arr[i]-(ldx-le[i]),arr[j]-(ri[i]-rdx));
		if(ch[i]!=ch[j])ans+=tmp;
		ldx+=tmp;rdx-=tmp;
		if(ldx>ri[i])i++;
		if(rdx<le[j])j--;
		continue;
	}
	cout<<ans;
	return 0;
}
