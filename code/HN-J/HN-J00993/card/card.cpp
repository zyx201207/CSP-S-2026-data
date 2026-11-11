#include <iostream>
#include <stdio.h>
#include <vector> 

int n, m;
int c[(int)5e5 + 10];
int last[(int)3e5 + 10];
int lastc[(int)5e5 + 10];
int ans[(int)3e5 + 10];
std::vector <int> card;

int main() 
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	std::cin >> n >> m;
	for(int i = 0;i < n;i++) {
		std::cin >> c[i];
		//ans[c[i]] = n;
	} 
	
	for(int i = n - 1; i >= 0;i--) {
		if(!last[c[i]]) {
			last[c[i]] = i;
			lastc[i] = -1;
		}
		else {
			lastc[i] = last[c[i]];
			last[c[i]] = i;
		}
	}
	
	for(int i = 0;i < n;i++) {
		int start = i;
		bool flag = true;
		while(start < n) {
			if(lastc[start] != -1)
				start = lastc[start];
			else {
				ans[c[++start]]++;
			}
		}
		ans[c[i]] += flag;
	}
		
	for(int i = 1;i <= m;i++) {
		std::cout << ans[i] << ' ';
	}
}

