#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
struct Seg{
	int length;
	char c;
} s[N];

int n;
long long cnt = 0;

int main()
{ 
		
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for (int i = 0;i<n;i++) cin >> s[i].length >> s[i].c;
	int l = 0,r = n - 1;
	while (l < r){
		if (s[l].length != 0 && s[r].length != 0)
		{
			int reduce = min(s[l].length, s[r].length);
			s[l].length -= reduce;
			s[r].length -= reduce;
			if (s[l].c != s[r].c) cnt += reduce;
			if (s[l].length == 0) l++;
			if (s[r].length == 0) r--;
		}
	}	
	cout << cnt;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
