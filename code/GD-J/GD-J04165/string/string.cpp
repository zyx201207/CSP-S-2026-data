#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum,ans;
char c[200005];
struct node{
	long long l;
	char id;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(c[i]==c[i-1])
		{
			s[j].l+=a[i];
		}
		else
		{
			j++;
			s[j].l=s[j-1].l+a[i];
			s[j].id=c[i];
		}
	}
	for(int i=1,k=j;i<=j,i<=k;i++)
	{
		long long op=sum-s[i].l+1;
		while(op<=s[k-1].l&&i<k)
		{
			if(s[k].id!=s[i].id)ans+=s[k].l-s[k-1].l;
			k--;
		}
		if(s[k].id!=s[i].id)ans+=s[k].l-op+1;
		s[k].l=op-1;
		if(s[k].l==s[k-1].l)k--; 
	}
	cout<<ans;
	return 0;
} 
