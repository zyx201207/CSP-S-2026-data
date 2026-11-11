#include<bits/stdc++.h>
using namespace std;	
int n;
long long a[200005];
long long ans;
string s;	
int r = 1,l=n;
long long rn = a[1],ln = a[n];
void ch()
{
	if(rn>ln)
	{
		rn-=ln;
		l--;
		ln = a[l];
	}else if(rn<ln)
	{
		ln-=rn;
		r++;
		rn = a[r];
	}else if(ln==rn)
	{
		r++;
		l--;
		rn = a[r];
		ln = a[l];
	}
	return ;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	r=1,l=n;
	rn = a[1],ln = a[n];
	while(r<=l)
	{
	//	cout<<" "<<r<<" "<<l<<" "<<ans<<endl;
	//	int b;
		//cin>>b;
		if(s[r] == s[l])
		{
			//cout<<"_";
			ch();
		}else if(s[r]!=s[l])
		{
			//cout<<"__";
			ans+=min(rn,ln);
			ch();
		}
		if(l==r&&(rn==1||ln==1))
		{
			//cout<<ans; 
			break;
		}
	}
	cout<<ans;
	return 0;
 } 
