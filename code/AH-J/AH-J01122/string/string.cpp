#include<bits/stdc++.h>
using namespace std;
int n;
string s;
const int N=2e5+5;
int a[N],x,ans;
bool check()
{
	for(int i=0,j=s.size()-1;i<=j;i++,j--)
		if(s[i]!=s[j])
			return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int y;
		cin>>y;
		a[x++]=y;
		char c;
		cin>>c;
		s+=c;
	}
	if(check())
	{
		cout<<0;
		return 0;
	}
	else
		cout<<1;
//	for(int i=0,j=s.size()-1;i<=j;i++,j--)
//	{
//		if(s[i]!=s[j]||a[i]!=a[j])
//		{
//			int mn;
//			if(a[i]<a[j])
//			{
//				
//			}
//			else
//				mn=j;
//			
//		}
//	}
//	cout<<ans;
	return 0;
}

