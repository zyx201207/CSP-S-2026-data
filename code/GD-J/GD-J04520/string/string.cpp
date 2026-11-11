#include<bits/stdc++.h>
using std::cin;
struct node
{
	char x;
	int num;
};
int n,l,r;
node ys[200005];
long long count;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ys[i].num);
		cin>>ys[i].x;
	}
	l=1;
	r=n;
	while(l<r)
	{
		if(ys[l].num==ys[r].num)//same
		{
			if(ys[l].x!=ys[r].x)
			{
				//plus
				count+=ys[l].num;
			}
			l++;
			r--;
		}
		else if(ys[l].num>ys[r].num)
		{
			if(ys[l].x!=ys[r].x)
			{
				//plus
				count+=ys[r].num;
			}
			ys[l].num-=ys[r].num;
			r--;
		}
		else if(ys[l].num<ys[r].num)
		{
			if(ys[l].x!=ys[r].x)
			{
				//plus
				count+=ys[l].num;
			}
			ys[r].num-=ys[l].num;
			l++;
		}
	}
	printf("%lld",count);
	return 0;
}
