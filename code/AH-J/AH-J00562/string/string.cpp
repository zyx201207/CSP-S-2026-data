#include <bits/stdc++.h>
using namespace std;
int n, a;
string b, c;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
    cin >> n;
    int num = -1;
    for (int i= 1; i <= n; i++){
        cin >> a >> b;
        num+= a;
        while(a--){
            c+=b;
        }
    }
    int i = 0, j = num;
    int sum = 0;
    while(i <= j){
        if (c[i] != c[j]){
            sum++;
        }
        i++;
        j--;
    }
    cout << sum;
    return 0;
}
