#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string ci;
	cin >> n;
	int ai;
	string S;
	int ans;
	for(int i=1;ai<=n;i++){
		cin >> ai >> ci;
		if(ci[ai]=ci[ai-1]){
			cout << 0;
		}
		else{
			ans++;
			cout << ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
