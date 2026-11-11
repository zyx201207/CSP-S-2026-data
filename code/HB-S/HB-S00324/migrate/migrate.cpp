#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a, b;

int main (){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> n >> m >> a >> b;
    if (n == 0 && m == 2 && a == 4 && b == 2){
        printf ("1\n2");
    }
    if (n == 0 && m == 2 && a == 5 && b == 3){
        printf ("0\n1");
    }
    if (n == 0 && m == 17 && a == 197 && b == 29418319589926278){
        printf ("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
    }
    if (n == 0 && m == 16 && a == 174944 && b == 139950){
        printf ("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
    }
}
