//GZ-J00128 遵义市第十二中学 戴沉鑫
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m, a[200005], b[200005];
	cin >> n>> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
    while(n){
        while(m){
            for(int i = n; i >= 2; i--)
                if(a[i] == a[1])
                    for(int j = 1; j < i; j++)
                        a[j] = 0;
        }
    }
    for(int i = 1; i <= m; i++)
        b[a[i]++;
    for(int i = 1; i <= n; i++)
        cout << b[i] << emdl;
	fclose(stdin);
	fclose(stdout);
}


