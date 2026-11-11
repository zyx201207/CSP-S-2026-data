#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010],cnt[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++){
		int s[500010],top = 0;
		for(int j = i;j <= n;j++){
			for(int k = 1;k <= top;k++){
				if(s[k] == a[j]){
					for(int l = top;l >= k;l--)
						top--;
					break;
				}
			}
			s[++top] = a[j];
		}
		for(int j = 1;j <= top;j++){
			//cout << s[j] << ' '
			cnt[s[j]]++;
		}
//		cout << '\n';
//		cout << top << '\n';
	}
	for(int i = 1;i <= m;i++)
		if(i != m)
			cout << cnt[i] << ' ';
		else
			cout << cnt[i];
	return 0;
} 
