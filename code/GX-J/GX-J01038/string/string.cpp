#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n, ma = 0;
    string s;
    cin >> n;
    vector<long long> a;
    vector<char> b;
    for(long long i=0; i<n; i++){
        long long o;
        char p;
        cin >> o >> p;
        a.push_back(o);
        b.push_back(p);
    }
    long long z = 0, x = a.size()-1;
    while(z < x && z != x){
        long long u = abs(a[z] - a[x]);
        if(b[z] != b[x]){
             ma += min(a[z], a[x]);
        }
        if(a[z] > a[x]){
            a[z] = u;
            x --;
        }else if(a[z] < a[x]){
            a[x] = u;
            z ++;
        }else{
            z ++;
            x --;
        }
    }
    cout << ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
