#include <iostream>
#include <string>

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;

	std::cin>>n;

	std::string S;

	for(int i=1; i<=n; ++i) {
		int sum;
		char op;

		std::cin>>sum>>op;

		std::string s;
		for(int j=1; j<=sum; ++j)
			s.push_back(op);

		S=S+s;
	}

	long long ans=0;

	for(int i=0; i<(int)S.size()/2; ++i)
		if(S[i]!=S[(int)S.size()-1-i])
			ans++;

	std::cout<<ans<<std::endl;

	return 0;
}

/*
Input:
3
2 a
2 b
1 c

Input:
3
2 a
2 b
2 c

*/
