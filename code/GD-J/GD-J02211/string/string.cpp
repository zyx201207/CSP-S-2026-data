#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int a;
		char c;
		scanf("%d %c",&a,&c);
		for(int i = 1;i <= a;i++){
			s = s + c;
		}
	}
	for(int i = 0;i < n;i++){
		if(s[i] != s[n - i - 1]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

