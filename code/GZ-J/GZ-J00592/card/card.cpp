//GZ-J00592
//遵义市新蒲新区滨湖中学
//邓佳琪 
#include <bits/stdc++.h>
using namespace std;
int cnt[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n, m;
	cin >> n >> m;

	int a[100000];
	for (int i = 0;i < n;i ++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for (int i = 0;i < n;i ++){
		if (cnt[i] != 0){
			cout << cnt[i] << " ";
		}
	}
	 
	 
	 return 0;
}

