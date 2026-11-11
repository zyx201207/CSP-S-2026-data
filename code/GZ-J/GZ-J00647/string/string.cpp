//GZ-J00647 盘州市第二中学 王玺童 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	int h=0;
	string s;
	cin>>n;
	int arr[n];
	char a[n];
	for(int i=0;i<n;i++)
	{
			cin>>arr[i]>>a[i];
			m+=arr[i];
			for(int j=0;j<arr[i];j++)
			s+=a[i];
	}
	if(m%2!=0)
	{
		for(int i=m/2+1;i<m;i++)
		{
			if(s[i]!=s[0]) h++;
		}
	}
	else
	{
		int u[m]={0,};
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(s[j]!=s[i]) u[i]++;
			}
			h=999;
			h=min(h,u[i]);
		}
		
	}
	cout<<h;
	return 0;
}
