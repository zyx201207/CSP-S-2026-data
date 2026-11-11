#include<bits/stdc++.h>
using namespace std;
int yu(int a,int b)
{
	int e=0;
	long long int a2=a,b2=b,cnt1=0,cnt2=0,cnte1=0,cnte2=0;
	vector<long long int> a3,b3,e3;
	for(int i=0;a!=0&&b!=0;i++)
	{
		if(a/10!=0)
			cnt1++;
		if(b/10!=0)
			cnt2++;
		a/=10;
		b/=10;
	}	
	
	for(int i=0;i<cnt1;i++)
	{
		if(a%2==0){
			a/=2;	
			cnte1++;}
	}	
	for(int i=0;i<cnt2;i++)
	{
		if(b%2==0){
			b/=2;
			cnte2++;}
	}
	if(cnte1>cnte2)
	{
		for(int i=0;i<cnte1-cnte2;i++)
			b3.push_back(0);
	}
	else if(cnte2>cnte1)
	{
		for(int i=0;i<cnte2-cnte1;i++)
			a3.push_back(0);
	}
	
	for(int i=0;i<cnt1;i++)
	{
		if(a2%2==0)
			a3.push_back(0);
		else
			a3.push_back(1);
	}
	for(int i=0;i<cnt2;i++)
	{
		if(b2%2==0)
			b3.push_back(0);
		else
			b3.push_back(1);
	}
	
	for(int i=0;i<a3.size();i++)
	{
		if(a3[i]==b3[i])
			e3.push_back(1);
		else
			e3.push_back(0);
	}
	
	for(int i=0;i<e3.size();i++)
		e+=pow(e3[i],pow(2,i));
	

	return e;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	vector<int> a;
	vector<int> ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		a.push_back(t);
		ans.push_back(t);
	}
	sort(a.begin(),a.end());
	sort(ans.begin(),ans.end());
	for(int i=m-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(i==j)
				continue;
			else
				ans[j]=yu(ans[j],a[i]);
		}
	}
	//for(int i=0;i<n;i++)
	//{
	//	cout<<ans[i];
	//}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-1];
	
	
	
	return 0;
}
