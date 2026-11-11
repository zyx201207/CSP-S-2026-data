#include<iostream>
struct node
{
	int a;
	char c;
};
node s[200000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
		std::cin>>s[i].a>>s[i].c;
	int area_left=0,area_right=n-1;
	unsigned long long answer=0;
	while(area_left<area_right)
		if(s[area_left].c!=s[area_right].c)
		{
			if(s[area_left].a>s[area_right].a)
			{
				answer+=s[area_right].a;
				s[area_left].a-=s[area_right].a;
				area_right--;
			}
			else if(s[area_left].a<s[area_right].a)
			{
				answer+=s[area_left].a;
				s[area_right].a-=s[area_left].a;
				area_left++;
			}
			else
			{
				answer+=s[area_left].a;
				area_left++;
				area_right--;
			}
		}
		else
		{
			if(s[area_left].a>s[area_right].a)
			{
				s[area_left].a-=s[area_right].a;
				area_right--;
			}
			else if(s[area_left].a<s[area_right].a)
			{
				s[area_right].a-=s[area_left].a;
				area_left++;
			}
			else
			{
				area_left++;
				area_right--;
			}
		}
	std::cout<<answer;
	return 0;
}
