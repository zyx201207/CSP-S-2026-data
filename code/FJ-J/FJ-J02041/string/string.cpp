#include <bits/stdc++.h>//完了，/和\分不清了 
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=2e5+10;
int n,a[N];
char ch[N];
ll ans;
int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
	for(int i=1,j=n;i<=j;)
	{
		if(ch[i]==ch[j])
		{
			if(a[i]<a[j]) a[j]-=a[i],i++;
			else if(a[i]>a[j]) a[i]-=a[j],j--;
			else i++,j--;
		}
		else
		{
			if(a[i]<a[j]) a[j]-=a[i],ans+=a[i],i++;
			else if(a[i]>a[j]) a[i]-=a[j],ans+=a[j],j--;
			else ans+=a[i],i++,j--;
		}
	}
	cout<<ans;
	return 0;
 }
