#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N=1e7;
int a,c;
int b[N];

signed main()
{
    freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>> a;
	for(int i=1;i<=a;i++){
        cin >> b[i];
	}
	for(int i=1;i<=a;i++){
        if(b[i]>c){
            c=b[i];
        }
	}
	cout << c;
	ios::sync_with_stdio(false);
	


	return 0;
}
