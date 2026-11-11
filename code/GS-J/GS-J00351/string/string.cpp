#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long x = 0,y = 0,z = 0,w = 0;
	int r = 1,l = n;
	for (int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        x += a[i];
	}
	cout << x;
	while (y < x/2 && r <= l){
        if (c[r] != c[l]){
            if (a[l] <= a[r] && z == 0){
                y += a[l];
                z = a[r]-a[l];
                l--;
            }
            else if (z != 0){
                if (z >= a[l]){
                    y += a[l];
                    z -= a[l];
                    l--;
                }
                else {
                    y += z;
                    a[l] -= z;
                    z = 0;
                }
            }
            else if (w != 0){
                if (w >= a[r]){
                    y += a[r];
                    w -= a[r];
                    r++;
                }
                else{
                    y += w;
                    a[r] -= w;
                    w = 0;
                }
            }
            else{
                y += a[r];
                w = a[l]-a[r];
                r++;
            }
        }
        else{
            break;
        }
	}
	cout << y;
	return 0;
}
