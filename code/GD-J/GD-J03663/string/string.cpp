#include <bits/stdc++.h>
using namespace std;
string s;
string s_;
int a[201000];
//int b[200100];
long long cnt=0;
/*
bool cmp(int x,int y)
{
	return x>y;
}
*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	//输入 
	for(int i=1;i<=n;i++)
	{
		int a_;
		char s_;
		cin>>a_>>s_;
		a[i-1]=a_;
		//b[i-1]=a_;
		s+=s_;
		
	}
	//cout<<s;
	bool pan=0;
	//sort(b,b+n,cmp);
	// 公约数化简a
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
		{
			pan=1;
		}
		else{
			pan=0;
			break;
		}
	}
	if(pan)
	{
		cout<<0;
		return 0;
	}
	
	bool allsame_=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			allsame_=1;
		}
		else{
			allsame_=0;
			break;
		}
	}
	if(allsame_==1)
	{
		s_=s;
	}
	else{
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s_+=s[i];
				//cout<<s_<<endl;
			}
		}
	}
	
	
	
	
	
	//判断要多少个 
	bool f=1;
	long long r=s_.size()-1;
	for(long long i=0;i<s_.size();i++)
	{
		if(s_[i]!=s_[r]&&i<=r)
		{
			cnt++;
			f=0;
		}
		r--;
	}
	f?  cout<<0  :  (allsame_ ? cout<<cnt*a[0]  :  cout<<cnt);
	//cout<<s_;
	return 0;
 } 
