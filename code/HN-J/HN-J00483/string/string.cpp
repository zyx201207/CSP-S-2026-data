#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
struct ns
{
	int number;
	char char_;
}new_s[MAXN];
int n,ans,len;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	len=n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char x1;
		scanf("%d %c",&x,&x1);
		new_s[i].number=x;
		new_s[i].char_=x1;
	}
	int l=1,r=len;
	bool flag=true;
	while(l<=r)
	{
		if(new_s[l].char_==new_s[r].char_&&new_s[l].number==new_s[r].number)l++,r--;
		else
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		cout<<ans;
		return 0;
	}
	l=1,r=len;
	while(l<=r)
	{
		if(new_s[l].char_==new_s[r].char_)
		{
			if(new_s[l].number>new_s[r].number)
			{
				ans+=new_s[l].number-new_s[r].number;
				new_s[r-1].number-=new_s[l].number-new_s[r].number;
			}
			else if(new_s[r].number>new_s[l].number)
			{
				ans+=new_s[r].number-new_s[l].number;
				new_s[l+1].number-=new_s[r].number-new_s[l].number;
			}
		}
		else  
		{
			if(new_s[r].number<new_s[l].number)
			{
				ans+=new_s[r].number;
				new_s[r].char_=new_s[l].char_;
			} 
			else 
			{
				ans+=new_s[l].number;
				new_s[l].char_=new_s[r].char_;
			}
			if(new_s[l].number>new_s[r].number)
			{
				ans+=new_s[l].number-new_s[r].number;
				new_s[r-1].number-=new_s[l].number-new_s[r].number;
			}
			else if(new_s[r].number>new_s[l].number)
			{
				ans+=new_s[r].number-new_s[l].number;
				new_s[l+1].number-=new_s[r].number-new_s[l].number;
			}
		}
		l++,r--;
		
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
