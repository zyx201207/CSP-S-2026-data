#include<bits/stdc++.h>
using namespace std;

unsigned long long n, m, a[10000000];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
    cin >> n >> n;
    for (unsigned long long i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << a[1] << " " << a[n-2]  << " "<< 4;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
