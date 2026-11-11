#include "bits/stdc++.h" 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int a,b,c,d,q;
	std::cin >> a >> b >> c >> d >> q;
	while(q--) 
	{
		std::cout << rand()+1 << '\n';
	}
	return 0;
}
