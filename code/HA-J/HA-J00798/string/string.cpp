#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	long long n,a,cnt=0;
	int mid=0,count=0;
	cin>>n;
	char b;
	string s[246881];
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(long long t=0;t<a;t++)
		{
			s[cnt]=b;
			cnt++;
		}
	}
                                                   //	for(int i=0;i<cnt;i++)
                                                 //	cout<<s[i];
                                                     //	cout<<cnt<<s[0];
	for(long long j=cnt-1;j>=cnt/2;j--)
	{
		if(s[j]!=s[mid])
		{
			count++;
                                                      //			cout<<s[mid]<<" "<<s[j]<<endl; 
		}	
		mid++;
		if(mid==cnt/2)
		break;
	}
	cout<<count;
	return 0;
	
}
	
//	long long n,a;
//	cin>>n;
//	char b,mid1,mid2;
//	int p[100000];
//	string s[200001];
//	int cnt=0,count=0;
//	for(long long i=0;i<n;i++)
//	{
//		cin>>a>>b;
//		s[i]=b;
//		p[i]=a;
//		cnt++;
//	}
//	int t=0;
//	for(int j=cnt;j>=cnt/2;j--)
//	{
//		if(s[j]!=s[t])
//		count=p[j]-p[t];
//		t++;
//	}
//	cout<<count;
//	return 0;
//}
