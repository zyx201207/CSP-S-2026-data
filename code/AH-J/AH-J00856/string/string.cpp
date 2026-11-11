#include<bits/stdc++.h>
using namespace std;
struct node{
	long long sum;
	char c;
}x[200005],v1[200005],v2[200005];
long long m1=0,m2=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long s1=0,s2=0,s3=0,ssum=0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>x[i].sum>>x[i].c;
		s1+=x[i].sum;
	}
	s1/=2;
	for(int i=1; ; i++)
	{
		if(s2==s1)
			break;
		else if(s2+x[i].sum<=s1)
		{
			v1[++m1].sum=x[i].sum;
			v1[m1].c=x[i].c;
			s2+=x[i].sum;
			x[i].sum=0;
		}
		else
		{
			v1[++m1].sum=s1-s2;
			v1[m1].c=x[i].c;
			x[i].sum=x[i].sum-s1+s2;
			s2=s1;
		}
	}
	for(int i=n; ; i--)
	{
		if(s3==s1)
			break;
		else if(s3+x[i].sum<=s1)
		{
			v2[++m2].sum=x[i].sum;
			v2[m2].c=x[i].c;
			s3+=x[i].sum;
			x[i].sum=0;
		}
		else
		{
			v2[++m2].sum=s1-s3;
			v2[m2].c=x[i].c;
			x[i].sum=x[i].sum-s1+s3;
			s3=s1;
		}
	}
	for(int l=1,r=1; l<=m1 && r<=m2;)
	{
		if(v1[l].c==v2[r].c)
		{
			if(v1[l].sum<v2[r].sum)
			{
				v2[r].sum-=v1[l].sum;
				l++;
			}		
			else if(v1[l].sum==v2[r].sum)
			{
			    l++;
				r++;
			}	
			else
			{
				v1[l].sum-=v2[r].sum;
				r++;
			}		
		}
		else
		{
			ssum+=min(v1[l].sum,v2[r].sum);
			if(v1[l].sum<v2[r].sum)
			{
				v2[r].sum-=v1[l].sum;
				l++;
			}		
			else if(v1[l].sum==v2[r].sum)
			{
				l++;
				r++;
			}	
			else
			{
				v1[l].sum-=v2[r].sum;
				r++;
			}
		}
	}
	cout<<ssum;
	return 0;
}
