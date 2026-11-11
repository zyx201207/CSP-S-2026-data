#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,r;
string s;
ll cnt;
struct stu{
	ll x;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(ll i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		s[i]=a[i].y;
	} 
	r=n-1;
	for(ll i=0;i<=r;)
	{
		if(a[i].x==0||a[r].x==0){
			i++;
			r--;
			continue;
		}
		if(s[i]!=s[r])
		{
			if(a[i].x<a[r].x)
			{
				a[i].y=a[r].y;
				cnt+=a[i].x;
				a[r].x-=a[i].x;
			}
			else
			{
				a[r].y=a[i].y;
				cnt+=a[r].x;
				a[i].x=a[r].x;
			}
		}
			r--;
	}
	cout<<cnt;
}
