#include "bits/stdc++.h" 
int main()	
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int a,q;
	std::cin >> a >> q;
	while(q--) 
	{
		std::cout << rand()+1 << '\n';
	}
	return 0;
}
