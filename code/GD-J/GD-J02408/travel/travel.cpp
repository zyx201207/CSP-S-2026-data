#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

namespace my {
	// Globals
	constexpr int N = 10;
	constexpr bool side[] = {false, false, false, true, true};
	
	char c1[N], s1[N], c2[N], s2[N], ans[N] = {};

	int main() {
		#ifndef LOCAL
			freopen("travel.in", "r", stdin);
			freopen("travel.out", "w", stdout);
		#endif

		scanf("%s%s%s%s", c1, s1, c2, s2);
		
		if (s1[2] == 'F') s1[2] = 'E';
		if (s2[2] == 'F') s2[2] = 'E';
		
//		printf("c1 = %s\ns1 = %s\nc2 = %s\ns2 = %s\n", c1, s1, c2, s2);
		
		strcpy(ans, "0000");
		
		if (!strcmp(c1, c2)) {	// 在同一节车厢 
			ans[0] = '1';
			
			if (!strncmp(s1, s2, 2)) {	// 在同一排 
				ans[1] = '1';
				
				if (side[s1[2] - 'A'] == side[s2[2] - 'A']) {	// 在同一侧 
					ans[2] = '1';
					
					if (abs(s1[2] - s2[2]) == 1)	// 相邻 
						ans[3] = '1'; 
				}
			} 
		}
		
		puts(ans);

		#ifndef LOCAL
			fclose(stdin);
			fclose(stdout);
		#endif

		return 0;
	}
}

int main() {
	my::main();

	return 0;
}

