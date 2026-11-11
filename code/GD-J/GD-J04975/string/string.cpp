#include <bits/stdc++.h>
using namespace std;
int n,a,cnt=0;
string s,c;
int ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a>>c;
		for (int j = cnt;j <cnt+a;j++){
			s+=c;
		}
		cnt+=a;
	}
	for (int i = 0;i<(cnt)/2;i++){
		if (s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
