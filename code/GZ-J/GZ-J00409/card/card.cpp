//GZ-J00409 遵义市第四中学 魏云藩 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("c.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n = 0,m = 0,tx = 0,ansx = 0;
	cin >> n;
	int a[n]={},t[100010]={},ans[m]={};
	for (int i = 0;i < n;i++){
		cin >> a[i];
	}
	for (int c = 0;c <= n;c++){
		for (int i = 0;i < c;i++){
			t[i] = a[i];
			tx++;
			for (int j = 0;j < tx;j++){
				if (t[i] == t[j]){
					t[i]=t[j];
					for (int b = i+1;b <= j;b++){
						t[b]=0;
					}
				}
			}
		}
		for (int i = 0;i < tx;i++){
			ans[t[i]-1] += 1;
		}
	}
	for (int i = 0;i < ansx;i++){
		cout << ans[i];
	}
	return 0;
}
	
