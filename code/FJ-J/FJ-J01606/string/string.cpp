//祝__wanghc__、__NightDay__、chen_14514、void_ghost、EternalArcana CSP rp++

//~ 《不可以，总司令》这一块(bushi ~ 
//~ But ~ 10:41 AC!

#include<bits/stdc++.h>
using namespace std;
#define write ios::sync_with_stdio(false);
#define by cin.tie(0);
#define __wanghc__ cout.tie(0);
#define ll long long

const ll N=2e6+10;
ll a[N];
char s[N];

int main()
{
	write by __wanghc__
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++) cin>>a[i]>>s[i];
	ll l=0,r=n-1,tot=0;
	while(l<r)
	{
		if(s[l]==s[r])
		{
			if(l==r-1) break;
			if(a[l]==a[r]) l++,r--;
			
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			
			else if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
		}
		else
		{
			if(a[l]==a[r])
			{	
				tot+=a[l];
				if(l==r-1) break;
				l++,r--;
			}
				
			else if(a[l]<a[r])
			{	
				tot+=a[l];
				a[r]-=a[l];
				l++;
			}
						
			else if(a[l]>a[r])
			{
				tot+=a[r];
				a[l]-=a[r];
				r--;
			}
		}		
	}   
	                                                                
	cout<<tot;
	return 0;
}

//Trick or treat!
