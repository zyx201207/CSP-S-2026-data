#include<bits/stdc++.h>
using namespace std;

int n,m;
int ans[300010],a[500010];
void f(int x){
	
	for(int i = x;i <= n;i++){
		for(int j = x;j < i;j++){
			if(a[i] == a[j]){
				x = i;
			}
		}
	}
	for(int i = x;i <= n;i++){
		ans[a[i]]++;
	}
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	memset(ans,0,sizeof(ans));
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		f(i);
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
