#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
struct fff{
	ll l;
	ll r;
	ll len;
	int type;
}; 
fff s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	ll n,add=0,ans=0,all;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char k;
		cin>>s[i].len>>k;
		s[i].type=k-'a'+1;
		s[i].l=s[i-1].r+1;
		s[i].r=s[i].l+s[i].len-1;
	}
	all=s[n].r;
	add=(s[n].r+1)/2;ll set;
	for(int i=1,j=n;s[i].r<add && s[j].l>add;)
	{
		if(s[i].len<s[j].len){
			if(s[i].type!=s[j].type) ans+=s[i].len;
			
			s[j].len-=s[i].len;
			s[j].r-=s[i].len;
			i++;
		}
		else if(s[i].len>s[j].len){
			if(s[i].type!=s[j].type) ans+=s[j].len;
			
			s[i].len-=s[j].len;
			s[i].l+=s[j].len;
			j--;
		}
		else if(s[i].len==s[j].len){
			if(s[i].type!=s[j].type) ans+=s[i].len;
			s[i].len-=s[j].len;
			s[i].l+=s[j].len;
			s[j].len-=s[i].len;
			s[j].r-=s[i].len;	
			i++,j--;		
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(add>=s[i].l && add<=s[i].r)
		{
			set=i;
			break;
		}
	}
	ll le,ri;
	le=add-s[set].l;
	if(all%2==0)le++;
	ri=s[set].r-add;
	if(le>ri)
	{
		if(s[set+1].type!=s[set].type)
		{
			ans+=le-ri;
		}
	}
	if(le<ri)
	{
		if(s[set-1].type!=s[set].type)
		{
			ans+=ri-le;
		}
	}
	cout<<ans;
	
	return 0;
}
