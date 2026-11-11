#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	char c;
	cin>>n;
	while(n--)
	{
		cin>>t>>c;
		while(t--)
		{
			s+=c;
		}
	}
	
	int p=s.size()/2;
	
	int l,r;
	if(s.size()%2==1)
	{
		//cout<<"长度为单数"<<"基准点为"<<p<<endl;
		l=r=p;
	}
	else
	{
		l=p-1,r=p;
		//cout<<"长度为双数"<<"基准点区间为"<<l<<"~"<<r<<endl;
	}
	
	char chp1=s[l],chp2=s[r];
	if(chp1!=chp2)
	{
		s[r]=chp1;
		ans++;
		//cout<<"区间内所有字符不相同，采用左边的作为基准点，修改右边的点"<<endl;
	}
	int cnt=0;
//	cout<<"开始尝试扩张区间"<<endl;
	while(s[l-1]==s[r+1]&&l-1>=0&&r+1<s.size())
	{
		cnt++;
		l--;
		r++;
		//cout<<"现在区间"<<l<<"~"<<r<<endl;
		//cout<<"扩张次数"<<cnt<<endl;
	}
	int chp1l=l,chp1r=r;
	if(chp1!=chp2)
	{
		//cout<<"采用右边的作为基准点，修改左边的点"<<endl; 
		l=p-1,r=p; 
		int cnt2=0;
		s[l]=s[r]=chp2;
		while(s[l-1]==s[r+1]&&l-1>=0&&r+1<s.size())
		{
			cnt2++;
			l--;
			r++;
			//cout<<"现在区间"<<l<<"~"<<r<<endl;
			//cout<<"扩张次数"<<cnt2<<endl;
		}
		if(cnt2<cnt)
		{
			//cout<<"比较后基准值1优于基准值2，将数据还原"<<endl;
			s[p-1]=s[p]=chp1;
			l=chp1l;r=chp1r;
		}
	}

	
	
	
	string s1,s2;
	for(int i=0;i<l;i++)
	{
		s1+=s[i];
	}
	for(int i=r+1;i<s.size();i++)
	{
		s2+=s[i];
	}
		
//	cout<<s<<endl;
//	cout<<p<<" "<<l<<" "<<r<<endl;
//	cout<<s1<<endl;
//	cout<<s2<<endl;
		
	int minn=1e18;
	int summ=0;
	for(int ii=0;ii<s1.size();ii++)
	{
		char cchp=s1[ii];
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!=cchp)
			{
				summ++;
			}
			if(s2[i]!=cchp)
			{
				summ++;
			}
		}
		minn=min(minn,summ);
		summ=0;
	}
	cout<<minn;
	
	return 0;
 } 
