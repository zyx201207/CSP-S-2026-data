#include "bits/stdc++.h"
#define int long long
using namespace std;

int n,cnt;
int a;
char b;

string c;
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		for(int j=1;j<=a;j++){
			c=c+b;
		}
	}
	cout << c;
    for(int i=1;i<=n;i++){


        for(int j=c.size();j>=i;j--){
            if(c[j]!=c[i]){
                cnt++;
            }

        }
    }

	
	cout << cnt/2;
	ios::sync_with_stdio(false);



	return 0;
}
