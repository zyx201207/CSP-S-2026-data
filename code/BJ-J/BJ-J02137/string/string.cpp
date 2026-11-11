#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
char ch[200005];
int sum[200005];
vector<int> front;
vector<char> fronts;
vector<int> back;
vector<char> backs;
int search(int num)
{
	int jump=log(sum[n])/log(2)+5;
	int jumplist[50],high=0;
	jumplist[0]=1;
	for(int i=1;i<=jump;i++) jumplist[i]=jumplist[i-1]*2;
	for(;jump>=0;jump--)
	{
		//cout<<"jump:"<<jumplist[jump]<<endl;
		if(jumplist[jump]+high<n && sum[jumplist[jump]+high]<=num)
		{
			high+=jumplist[jump];
		}
	}
	return high;
}
unsigned int solve()//two point
{
	unsigned int ans=0,l=0,r=0;
	while(l<front.size() || r<back.size())
	{
		if(front[l]<back[r])
		{
			//cout<<"fb";
			if(fronts[l]!=backs[r]) 
			{
				ans+=front[l];
				fronts[l]=backs[r];
			}
			back[r]-=front[l];
			l++;
		}
		else if(front[l]==back[r])
		{
			//cout<<"sa";
			if(fronts[l]!=backs[r]) 
			{
				ans+=front[l];
				fronts[l]=backs[r];
			}
			back[r]=0;
			front[l]=0;
			l++;r++;
		}
		else
		{
			//cout<<"ff";
			if(fronts[l]!=backs[r]) 
			{
				ans+=back[r];
				backs[r]=fronts[l];
			}
			front[l]-=back[r];
			r++;
		}
	}
	return ans;
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		sum[i]=sum[i-1]+a[i]*1LL;
	}
	if(sum[n]%2==0)
	{
		int seaval=search(sum[n]/2);
		if(sum[seaval]!=sum[n]/2)
		{
			int q=sum[n]/2-sum[seaval];
			int nu=a[seaval+1];
			a[seaval+1]=q;
			for(int i=n;i>=seaval+2;i--)
			{
				a[i+1]=a[i];ch[i+1]=ch[i];
			}
			a[seaval+2]=nu-q;
			ch[seaval+2]=ch[seaval+1];
			n++;
			//cout<<seaval<<' '<<q<<' '<<nu;
			for(int i=1;i<=n;i++)
			{
				//cout<<a[i]<<ch[i]<<endl;
				sum[i]=sum[i-1]+a[i]*1LL;
			}
			seaval=search(sum[n]/2);
		}
		for(int i=1;i<=seaval;i++)
		{
			front.push_back(a[i]);
			fronts.push_back(ch[i]);
		}
		for(int i=n;i>=seaval+1;i--)
		{
			back.push_back(a[i]);
			backs.push_back(ch[i]);
		}
	}
	else
	{
		int seaval=search(sum[n]/2);
		int q=sum[n]/2-sum[seaval];
		int nu=a[seaval+1];
		a[seaval+1]=q;
		for(int i=n;i>=seaval+2;i--)
		{
			a[i+1]=a[i];ch[i+1]=ch[i];
		}
		a[seaval+2]=nu-q-1;
		ch[seaval+2]=ch[seaval+1];
		n++;
		//cout<<seaval<<' '<<q<<' '<<nu;
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i]<<ch[i]<<endl;
			sum[i]=sum[i-1]+a[i]*1LL;
		}
		seaval=search(sum[n]/2);
		for(int i=1;i<=seaval;i++)
		{
			front.push_back(a[i]);
			fronts.push_back(ch[i]);
		}
		for(int i=n;i>=seaval+1;i--)
		{
			back.push_back(a[i]);
			backs.push_back(ch[i]);
		}
	}
	
	/*
	for(unsigned int i=0;i<front.size();i++)
	{
		cout<<front[i]<<' ';
	}
	cout<<endl;
	for(unsigned int i=0;i<fronts.size();i++)
	{
		cout<<fronts[i]<<' ';
	}
	cout<<endl;
	for(unsigned int i=0;i<back.size();i++)
	{
		cout<<back[i]<<' ';
	}
	cout<<endl;
	for(unsigned int i=0;i<backs.size();i++)
	{
		cout<<backs[i]<<' ';
	}
	cout<<endl;*/
	
	
	cout<<solve();
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
 */
