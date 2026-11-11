#include <bits/stdc++.h>
using namespace std;
long long t[200005][26];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long num=0;
	string a="",b="",s="";
	for(int i=1;i<=n;i++)
	{
		long long x;
		char c;
		cin>>x>>c;
		
		for(int j=0;j<x;j++)
		{
			s+=c;
		}
	}
	
	//cout<<s<<endl;

	if(s.size()%2==1)
	{//substr
		for(int i=0;i<s.size()/2;i++)
		{
			a+=s[i];
		}
		for(int i=s.size()-1;i>=s.size()/2+1;i--)
		{
			b+=s[i];
		}
	}
	else
	{
		for(int i=0;i<s.size()/2;i++)
		{
			a+=s[i];
		}
		for(int i=s.size()-1;i>=s.size()/2;i--)
		{
			b+=s[i];
		}
	}
	//cout<<a<<" "<<b;
	for(int i=0;i<max(a.size(),b.size());i++)
	{
		if(a[i]!=b[i])
		{
			num++;
		}
		else
		{
			continue;
		}
	}
	cout<<num;
	return 0;
	
}
//#include <bits/stdc++.h>
//using namespace std;
//long long t[200005][27];
//int main()
//{
//	int n;
//	cin>>n;
//	long long a,b;
//	long long idx,idy,zhongzhi=0;
//	long long num=0;
//	
//	for(int i=1;i<=n;i++)
//	{
//		long long x;
//		char c;
//		cin>>x>>c;
//		int q=c-'a'+1;
//	    t[i][q]+=x;
//	    zhongzhi+=x;
//	}
//	zhongzhi/=2;
//	long long sum=zhongzhi;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=26;j++)
//		{
//			sum-=t[i][j];
//			if(sum<=0)
//			{
//				idx=i,idy=j;
//			}
//		}
//	}
////	cout<<zhongzhi<<endl;
////	for(int i=1;i<=n;i++)
////	{
////		for(int j=1;j<=26;j++)
////		{
////		    cout<<t[i][j]<<" "	;
////		}
////		cout<<endl;
////		
////	}
//	long long a1=zhongzhi,a2=zhongzhi,z1=0,z2=0,zz=1,zx,zy;
//	while(zhongzhi>0)
//	{
//	
//		if(z1==0)
//		{
//			for(int i=1;i<=26;i++)
//			{
//				if(t[zz][i]!=0)
//				{	
//					zx=i;
//					
//				//	cout<<zx<<endl;
//					z1=t[zz][i];
//					break;
//				}
//			}
//		}
//		if(z2==0)
//		{
//			for(int i=1;i<=26;i++)
//			{
//				if(t[n-zz+1][i]!=0)
//				{
//					
//					zy=i;
//					z2=t[n-zz+1][i];
//					//cout<<zy<<endl;
//					break;
//				}
//			}
//		}
//		long long r=min(z1,z2);
//		if(zx!=zy)
//		{
//			num+=r;
//		}
//		//cout<<zx<<" "<<zy<<" "<<z1<<" "<<z2<<endl; 
//	//	cout<<num<<endl;
//		
//		z1-=r;
//		z2-=r;
//		//cout<<zx<<" "<<zy<<" "<<z1<<" "<<z2<<endl;	
//		zz++;
//		zhongzhi-=r;
//		//cout<<"zhi"<<zhongzhi<<endl;
//	}
//	//cout<<s<<endl;
//    
//	cout<<num;
//	return 0;
//	
//}
