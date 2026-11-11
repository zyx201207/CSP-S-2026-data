#include <bits/stdc++.h>
using namespace std;

struct node{
	unsigned long long a;
	char c;
}g[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    long long minv = 1e9;
    for (int i = 1; i <= n; i ++ ){
    	cin >> g[i].a >> g[i].c;
	}
	//cout << s <<endl;
	long long ans = 0,l = 0,r = n - 1;
	//cout << l << r << endl;
	do{
		if (g[l].c != g[r].c){
			minv = min(g[l].a, g[r].a);
			g[l].a -= minv;
			g[r].a -= minv;
			ans += minv;
		}else{
			minv = min(g[l].a, g[r].a);
			g[l].a -= minv;
			g[r].a -= minv;
		}
		if (g[l].a == 0){
			l++;
		}
		if (g[r].a == 0){
			r--;
		}
//		cout << l << r << endl;
//		cout <<minv<< " "<< ans << endl;
	}while(l<r);
	
    cout << ans;
    
    return 0;
}

