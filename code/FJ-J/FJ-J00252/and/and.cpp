#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()//reserve
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,x=0;
	cin >> n >> m;
	vector<ll> v(n);
	vector<string> vv(n);
	for(ll i=0;i<n;i++)
	{
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	
	for(ll i=0;i<n;i++)
	{
		ll a=v[i];
		string s="";
		for(;a;)
		{
			s+=char(a%2+'0');
			a/=2;
		}
		reverse(s.begin(),s.end());
		
		vv[i]=s;
	}

	for(ll i=0;i<n-m;i++)
	{
		string mj2="";
		for(ll j=i;j<j+m-1;j++)
		{	
			//cout<< vv[j] << " ";
			if(j==i)
			{
				ll q=max(vv[j].size(),vv[j+1].size());
				for(ll k=0;k<q;k++)
				{
					
					string a=vv[j],b=vv[j+1];
					if(a[k]=='/0')a[k]+='0';
					if(b[k]=='/0')b[k]+='0';
					if(a[k]==b[k]) mj2+='1';
					else mj2+='0';
				}
				break;
			}	
			
			string mj="";
			ll q=max(mj2.size(),vv[j+1].size());
			for(ll k=0;k<q;k++)
			{
			
				string a=mj2,b=vv[j+1];
				if(a[k]=='/0')a[k]+='0';
				if(b[k]=='/0')b[k]+='0';
				if(a[k]==b[k]) mj+='1';
				else mj+='0';
			}
			mj2=mj;
		}
		
		ll smj=0;
	  	ll kjs=mj2.size();
		for(ll j=1,k=0;k<kjs;k++,j*=2)
		{
			smj+=(mj2[k]-'0')*j;
		}
		if(i==0) x=smj;
		else if(x<smj) x=smj;
	}
	cout << x;

	return 0;
}
