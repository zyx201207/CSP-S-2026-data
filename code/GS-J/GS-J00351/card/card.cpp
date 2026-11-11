#include <bits/stdc++.h>
using namespace std;
int n,m,a[300005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
        cin >> a[i];
	}
	int b[300005],c[n+1];
	int l = 1,ans = 0;
	for (int i = 1;i <= n;i++){
        l = 1,ans = 0;
        for (int j = 1;j <= n;j++){
            c[j] = 0;
        }
        for (int j = i;j <= n;j++){
            for (int k = 1;k <= l;k++){
                if (a[j] == b[k]){
                    l = k;
                }
            }
            b[l] = a[j];
            l++;
        }
        for (int j = 1;j <= l;j++){
            c[b[j]]++;
        }
	}
	for (int j = 1;j <= n;j++){
       cout << c[j];
    }
	return 0;
}
