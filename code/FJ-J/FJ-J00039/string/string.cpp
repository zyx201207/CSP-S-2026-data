#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n;
ll sum[N],mid,mid_num;
ll a[N];
char c[N];
ll last[N];
ll len=0;
ll mx=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		sum[i]=sum[i-1]+a[i];
		mx=max(mx,a[i]);
	} 
	if(n*mx<=1e8)
	{
		string s;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
		}
		ll ans=0;
		for(int i=0;i<(s.size()-1)/2;i++)
		{
			if(s[i]!=s[s.size()-i-1])
			{
				ans++; 
			}
		}
		cout<<ans;
		return 0;
	}
	ll s,m;
	mid=(sum[n]+1)/2;
	ll now=0;
	for(int i=1;i<=n;i++)
	{
		now+=a[i];
		if(now>=mid&&(now-a[i])<=mid)
		{
			mid_num=i-1;
			break;
		}
	}
	for(int i=n;i>=1;i--) last[i]=last[i+1]+a[i];
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' '<<last[i]<<'\n';
	ll ans=0;
	ll j=n;//目前对应走到哪里了 
	//s当前走到位置（源字符串） 
	for(int i=1;i<=mid_num;i++)
	{
		if(i==mid_num)
		{
			s=mid;
			len=mid-sum[mid_num-1];
			m=(sum[n]-s+1);
		}
		else
		{
			len=a[i];
			s+=a[i];
			m=(sum[n]-s+1);
		}
		ll end=sum[n]-last[j+1]+1;
	//	cout<<i<<"\n";
	//	cout<<s<<' '<<now<<' '<<m<<'\n'; 
		while(j&&(end>m))
		{	
			end=sum[n]+1-last[j+1];
			ll st=sum[n]+1-last[j];
			if(st<=m&&m<=end)
			{
				break;
			}
		//	cout<<m<<' '<<j<<' '<<now<<' '<<st<<'\n';
			if(c[i]!=c[j])
			{
				ans+=a[j];
			}
			len-=a[j];
			j--;
		//	cout<<ans<<'\n';
		}
		if(c[j]!=c[i])
		{
			ans+=len;
		}
	}
	cout<<ans;
	return 0;
}
/*
aaaabcd

4
4 a
1 b
1 c
1 d


aabbc
4

2

3
2 a
2 b
1 c

n个连续的段
第i(1≤i≤n)段由ai个小英文字母ci 构成
最少需要修改多少个位置的字符，才能将S改成回文串。

aabbc

n<=2e5+5
a[i]<=1e9+5

L<=2e14

aaaaa

修改前和修改后是一样的

a[1]*c[1]+a[2]*c[2]+a[3]*c[3]+...+a[n]*c[n]

abbbcaa

abbbbba
2

ON

mid:x

1~mid

000111111001

for i 1~mid
	
位置sum
改
右边碰到边界：
判左边 



NlogN
*/ 
