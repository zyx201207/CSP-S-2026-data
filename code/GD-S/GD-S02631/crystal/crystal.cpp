#include<iostream>
using namespace std;
const int N = 5e5 + 5;
long long ans1, ans2;
long long a[N], d[N], pre1[N], pre2[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        d[i] = abs(a[i] - a[i - 1]);
    }
    for(int i = 2; i <= n; i++){
        pre1[i] = abs(pre1[i - 1] + d[i]);
        if(m < pre1[i]){
        	ans1 = i - 1;
        	break;
		}
		if(i == n) ans1 = n;
    }
    for(int i = n - 1; i >= 1; i--){
        pre2[i] = abs(pre2[i + 1] + d[i + 1]);
        //cout << pre2[i] << " ";
        if(m < pre2[i]){
        	ans2 = n - i;
        	break;
		}
		if(i == n - 1) ans2 = n;
    }
    cout << max(ans1, ans2);
    return 0;
}

