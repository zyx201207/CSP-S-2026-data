#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s,l,r,cl,cr,ans;
string t[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){cin>>a[i]>>t[i];s+=a[i];}
	r=n-1;
	while(s>1)
	{
		if(l==r)  break;
		if(t[l]!=t[r])
		{
			if(a[l]>a[r])
			{
				cr=a[r];
				a[l]-=cr;
				s-=cr;
				ans+=cr;
				r--;
			}
			else  if(a[l]<a[r])
			{
				cl=a[l];
				a[r]-=cl;
				s-=cl;
				ans+=cl;
				l++;
			}
			else  if(a[l]==a[r])
			{
				s-=a[l]+a[r];
				ans+=a[l];
				l++,r--;
			}
		}
		else  if(t[l]==t[r])
		{
			if(a[l]>a[r])
			{
				cr=a[r];
				a[l]-=cr;
				s-=cr;
				r--;
			}
			else  if(a[l]<a[r])
			{
				cl=a[l];
				a[r]-=cl;
				s-=cl;
				l++;
			}
			else  if(a[l]==a[r])
			{
				s-=a[l]+a[r];
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
