#include<bits/stdc++.h>
using namespace std;
struct node 
{
	long long a;//个数 
	char b;//字母 
}s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b;
	}
	long long ans=0;
	bool bj=false;
	long long al=s[1].a, ar=s[n].a;
	for(int l=1,r=n;l<=r;)
	{
		
		if(l!=r)//不为同一项 
		{
			if(s[l].b==s[r].b) //不用改 
			{
				if(al>ar){
					al-=ar;
					r--;
					ar=s[r].a;
				}	
				else if(al<ar) {
					ar-=al;
					l++;
					al=s[l].a;
				}
				else if(al==ar) {
					ar=0,al=0;
					r--;
					ar=s[r].a;
					l++;
					al=s[l].a;
				}
			}
			else//需要改 
			{
				if(al>ar){
					ans+=ar; 
					al-=ar;
					r--;
					ar=s[r].a;
				}	
				else if(al<ar) {
					ans+=al;
					ar-=al;
					l++;
					al=s[l].a;
				}
				else if(al==ar) {
					ans+=al;
					ar=0,al=0;
					r--;
					ar=s[r].a;
					l++;
					al=s[l].a;
				}
			} 
		} 
		else//是回文 
		{
			break;
		} 
	}
	cout<<ans;
	return 0;
}

