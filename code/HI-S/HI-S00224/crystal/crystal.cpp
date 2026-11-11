#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],s[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	scanf("&d",a[i]);
    	b[a[i]]++;
    	s[i]+=s[i-1];
	}
	if(s[n]<m)
	{
		cout<<n;
	}
	sort(a,a+n);
	int l=0,r=n,mid,sum=0,cnt=0;
    mid=(l+r)/2;
    for(int i=mid-1;i>=0;i--)
    {
  	sum+=a[mid]-a[i];
    	cnt++;
    	if(sum==m)
    	{
    		cnt+=b[mid];
    		cout<<cnt;
    		return 0;
		}
	}
    cout<<cnt;
	return 0;
}

