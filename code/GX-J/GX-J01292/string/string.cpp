#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::freopen("string.in", "r", stdin);
	std::freopen("string.out", "w", stdout);
	
	int n;
	std::cin >> n;
	std::string s;
	for(int i=0;i<n;i++)
	{
		std::string ss;
		std::cin>>ss;
		s+=ss;
	}
	int ans=0;
	for(int i=0;i<=s.size()/2;i++)
	{
		if(s[i]==s[s.size()-i-1])ans++;
	}
	std::cout<<ans;
}
