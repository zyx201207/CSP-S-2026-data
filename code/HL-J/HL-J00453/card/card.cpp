#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],s[500005],r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int x = 1;x <= n;x++,r = 0){
		memset(s,0,sizeof(s));
		for(int i = x;i <= n;i++){
			for(int j = 1;j <= r;j++)
				if(a[i] == s[j]){
					r = j - 1;
					break;
				}
			s[++r] = a[i];
		}
		for(int i = 1;i <= r;i++)
			f[s[i]]++;
	}
	for(int i = 1;i <= m;i++)
		cout << f[i] << " ";
	return 0;
}
