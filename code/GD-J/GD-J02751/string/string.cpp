#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
const int M=2e5+1;
int n,a[M];
long long len=0;
char c[M];
string s;
inline long long Min(long long a,long long b)
{	return a>b?b:a;
}
signed main()
{	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{	cin>>a[i]>>c[i];
		len+=a[i];
		//cout<<a[i]<<" "<<c[i]<<"\n";
//		for(int j=1;j<=a[i];j++)
//			s+=c[i];
	}
	long long ans=0,mid=len/2;
	//cout<<len<<" "<<mid<<' '<<s[mid];
//	int l=mid,r=mid;
//	if(len%2!=0)
//		l--,r++;
//	else
//		l--;
//	while(l>=0&&r<=s.size())
//	{	if(s[l]!=s[r])
//			ans++;
//		l--,r++;
//	}
	long long l=0,r=len,curl=0,curr=n-1,step=1;
	int al=0,ar=0;
	while(curl<curr)
	{	if(c[curl]!=c[curr])
		{	int jian=Min(a[curl],a[curr]);
			ans+=jian;
			a[curl]-=jian,a[curr]-=jian;
//			cout<<"1 "<<step<<" "<<jian<<" "<<a[curl]<<" "<<a[curr]<<"\n";
//			step++;
		}
		else
		{	int jian=Min(a[curl],a[curr]);
			a[curl]-=jian,a[curr]-=jian;
//			cout<<"2 "<<step<<" "<<jian<<" "<<a[curl]<<" "<<a[curr]<<"\n";
//			step++;
		}
		if(a[curl]==0)
			curl++;
		if(a[curr]==0)
			curr--;
	}
	cout<<ans<<"\n";
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
//I Love CCF!
