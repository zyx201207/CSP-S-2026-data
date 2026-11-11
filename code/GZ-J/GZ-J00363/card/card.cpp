//贵阳市第三中学 游子乐GZ-J00363 
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n,m,g = 0;
int a[N],cnt[N],b[N];
bool vis[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1+g,j = 1;i <= n;i++){
		if(!vis[a[i]]){
			b[j] = a[i];
			j++;
			vis[a[i]] = 1;
		}else{
			j = 1;
			b[j] = a[i];
			vis[a[i]] = 1;
		}
		if(i == n){
			for(int l = 1;l <= j;l++){
				cnt[b[l]]++;
			}
			memset(vis,0,sizeof(vis));
			j = 1;
			g++;
			i = 1;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
