#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
char s1[100010];
string s;
int ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s1[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=s1[i];
		}
	}
	bool w=true;
	int l=s.size(),mid=0;
	for(int i=1;i<=n;i++)
	{
		if(s1[i]!=s1[1])
		{
			w=false;
		}
	 }
	 if(w)
	 {
	 	cout<<0;
	 }
	 else if(n==1)
	 {
	 	cout<<0;
	 }


	 //if(l%2==1)
	 //{
	 	//mid=l/2+1;
	 //}
	 //else
	 //{
	 	//mid=l/2;
	 //}
	 //for(int i=1;i<mid;i++)
	 //{
	 	//for(int j=l;j>=mid+1;j--)
	 	//{
	 		//if(s[i]!=s[j])
	 		//{
			    //ans++;
			//}
		//}
	//}
	//cout<<ans/2;
	return 0;
}
